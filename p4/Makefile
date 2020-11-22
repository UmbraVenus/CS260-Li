CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJTS = app.o website.o table.o 

app: $(OBJTS)

app.o: website.h table.h

website.o: website.h

table.o: table.h website.h

clean:
	rm app *.o