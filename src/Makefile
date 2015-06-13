CC = gcc
CFLAGS = -std=c99
LDFLAGS = -lm
OUT = out
PROG = $(OUT)/main

SRC = $(wildcard *.c)
OBJS = $(SRC:%.c=objs/%.o)


.PHONY: all

all: $(PROG)

$(PROG) : $(OBJS)
	mkdir -p $(OUT)
	$(CC) $(LDFLAGS) -o $@ $^

objs/%.o : %.c %.h
	mkdir -p objs/
	$(CC) $(CFLAGS) -o $@ -c $<

# Génère le fichier mmain.png contenant
# la représentation graphique de psi
plot: $(PROG)
	./$(PROG) > $(OUT)/main.data
	gnuplot -e "set terminal png; plot '$(OUT)/main.data' with lines" > $(OUT)/main.png
	xdg-open $(OUT)/main.png

# Détruit tout les fichiers *.o, l'executable
# ainsi que les fichiers générés par la
# commande  plot
clear:
	rm -f objs/*.o $(PROG) $(OUT)/main.data $(OUT)/main.png
