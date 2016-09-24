# edification des liens
Programme : main.o Grammar.o Phrase.o
	g++ -std=c++14 main.o Grammar.o Phrase.o -o Programme
	rm -rf *.o

# compilation en fichier objet
main.o : main.cpp Grammar.cpp Phrase.cpp
	g++ -std=c++14 -c main.cpp -o main.o

Grammar.o : Grammar.cpp
	g++ -std=c++14 -c Grammar.cpp -o Grammar.o

Phrase.o : Phrase.cpp
	g++ -std=c++14 -c Phrase.cpp -o Phrase.o

# suppression des fichiers temporaires
clean:
	rm -rf *.o

# suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
mrproper: clean
	rm -rf Programme
