#include "unp.h"

sctp_assoc_t
sctp_address_to_associd(int sock_fd, struct sockaddr *sa,
                        socklen_t salen)
{
   struct sctp_paddrinfo sp;
   socklen_t siz;

   siz = sizeof(struct sctp_paddrinfo);
   bzero(&sp, siz);
   memcpy(&sp.spinfo_address, sa, salen);
   Sctp_opt_info(sock_fd, 0, SCTP_GET_PEER_ADDR_INFO,
                 &sp, &siz);
   return sp.spinfo_assoc_id;
}
