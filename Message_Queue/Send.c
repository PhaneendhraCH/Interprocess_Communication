/*
    ftok(): is use to generate a unique key.

    msgget(): either returns the message queue identifier for a newly created message queue or returns the identifiers for a queue which exists with the same key value.

    msgsnd(): Data is placed on to a message queue by calling msgsnd().

    msgrcv(): messages are retrieved from a queue.

    msgctl(): It performs various operations on a queue. Generally it is use to destroy message queue.

 */

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;

int main()
{
    int msgid;

    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(9, 0666 | IPC_CREAT);
    message.mesg_type = 1;

    printf("Write Data : ");
    fgets(message.mesg_text,MAX,stdin);

    // msgsnd to send message
    msgsnd(msgid, &message, sizeof(message), 0);

    // display the message
    printf("Data send is : %s \n", message.mesg_text);

    return 0;
}
