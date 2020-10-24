CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJTS = app.o individual.o customer.o queue.o stack.o 

app: $(OBJTS)

app.o: individual.o customer.o queue.o

individual.o: individual.h

customer.o: customer.h

stack.o: individual.h stack.h

queue.o: queue.h customer.o

clean:
	rm app *.o