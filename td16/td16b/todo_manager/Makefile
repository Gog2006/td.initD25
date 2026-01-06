
CC = gcc
CFLAGS = -Wall -Werror -std=c23
SRCS = main.c lib/taches.c
TARGET = todo

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) todo.txt tests/sortie1.txt tests/sortie2.txt

test: clean all
	@echo "# Initialisation du fichier de test"
	echo "Tâche 1" > todo.txt
	@echo "# Test 1: ajout et listage"
	./todo add "Tâche 2"
	./todo add "Tâche 3"
	./todo list > tests/sortie1.txt
	@echo "# Vérification des résultats (Test 1)"
	@diff tests/sortie1.txt tests/1-sortie.txt
	@echo "# Vérification du contenu de todo.txt après ajout"
	@diff todo.txt tests/1-todo.txt
	@echo "# Test 2: marquage comme terminée et listage"
	./todo do 2
	./todo list > tests/sortie2.txt
	@echo "# Vérification des résultats (Test 2)"
	@diff tests/sortie2.txt tests/2-sortie.txt
	@echo "# Vérification de la ligne marquée dans todo.txt"
	@grep -E "^x [0-9]{4}-[0-9]{2}-[0-9]{2} Tâche 2" todo.txt && echo "Test 2 réussi" || (echo "Test 2 échoué"; exit 1)
	@echo "Tests terminés"

