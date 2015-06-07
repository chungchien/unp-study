#include "unp.h"

int main(int argc, char *argv[])
{
   int sock_fd;
   struct sockaddr_in servaddr;
   struct sctp_event_subscribe events;
   struct sctp_initmsg initmsg;
   int echo_to_all = 0;

   if (argc < 2)
      err_quit("Missing host argument - use '%s host [echo]'\n",
               argv[0]);
   if (argc > 2) {
      printf("Echoing messages to all streams\n");
      echo_to_all = 1;
   }
   sock_fd = Socket(AF_INET, SOCK_SEQPACKET, IPPROTO_SCTP);
   bzero(&initmsg, 0);
   initmsg.sinit_num_ostreams = SERV_MORE_STRMS_SCTP;
   Setsockopt(sock_fd, IPPROTO_SCTP, SCTP_INITMSG,
              &initmsg, sizeof(initmsg));
   bzero(&servaddr, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(SERV_PORT);
   Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

   bzero(&events, sizeof(events));
   events.sctp_data_io_event = 1;
   Setsockopt(sock_fd, IPPROTO_SCTP, SCTP_EVENTS,
              &events, sizeof(events));
   if (echo_to_all == 0)
      sctpstr_cli(stdin, sock_fd, (SA *) &servaddr, sizeof(servaddr));
   else
      sctpstr_cli_echoall(stdin, sock_fd, (SA *) &servaddr,
                          sizeof(servaddr));

   Close(sock_fd);
   return 0;
}
