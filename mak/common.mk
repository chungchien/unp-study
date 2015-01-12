dirs:
	@for dir in $(DIRS) ; do \
	if [ -d $$dir ]; then true;\
	else mkdir -p $$dir ; echo "mkdir -p $$dir"; fi; \
	done
