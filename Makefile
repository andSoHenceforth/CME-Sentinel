CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lcurl
TARGET = cme_ingestor

all: $(TARGET)

$(TARGET): cme_ingestor.c
	$(CC) $(CFLAGS) cme_ingestor.c -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
