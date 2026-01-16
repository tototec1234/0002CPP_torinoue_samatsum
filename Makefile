MAKE = make
MAKEFLAGS += --no-print-directory

# CLEAN = clean

EX00 = ex00
EX01 = ex01

# $(CLEAN):
# 	$(MAKE) $(CLEAN) -C $(EX00)
# 	$(MAKE) $(CLEAN) -C $(EX01)

all:
	$(MAKE) -C $(EX00)
	$(MAKE) -C $(EX01)

fclean:
	$(MAKE) fclean -C $(EX00)
	$(MAKE) fclean -C $(EX01)

clean:
	$(MAKE) clean -C $(EX00)
	$(MAKE) clean -C $(EX01)

re:
	$(MAKE) re -C $(EX00)
	$(MAKE) re -C $(EX01)

run:
	$(MAKE) run -C $(EX00)
	$(MAKE) run -C $(EX01)

test:
	$(MAKE) test -C $(EX00)
	$(MAKE) test -C $(EX01)

.PHONY: all clean fclean re test run