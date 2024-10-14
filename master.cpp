#include <iostream>
#include <unistd.h>  // For getpid()
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <string>

using namespace std;


// example : ./master 3
int main(int argc, char *argv[])
{
    // convert argv[1] into int
    int x = stoi(argv[1]);

    // get master PID
    pid_t masterPID = getpid();
    cout << "Master, PID " << masterPID << " begins execution" << endl;

    // get message queue ID
    key_t key = ftok("queuefile", 65); // generate unique key
    int msgid = msgget(key, 0666 | IPC_CREAT); // create msg queue with read/write perms

    if (msgid == -1) 
    {
        perror("msgget error");
        return 1;
    }

    cout << "Master acuired a message queue, id " << msgid << endl;

    // creating sender child
    pid_t sender = fork();
    if (sender == 0) 
    {
        
    }

    
    
    return 0;
}