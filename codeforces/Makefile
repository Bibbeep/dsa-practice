ONLINEJUDGE ?= codeforces

ifeq ($(ONLINEJUDGE),uva)
	CFLAGS = -lm -lcrypt -O2 -pipe -DONLINE_JUDGE
else
	CFLAGS = -O3 -std=gnu11
endif

FILE ?= main.c

run: solutions/$(FILE)
	gcc $(CFLAGS) -o $@ solutions/$(FILE)
clean:
	rm -f run
