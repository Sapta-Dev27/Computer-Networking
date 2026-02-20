#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define TIMEOUT 2 

typedef struct {
    int data ;
    int seq_no ;
} Frame ;

typedef enum {
    IDLE ,
    WAITING_FOR_ACK
} State ;

bool isError(){
    return (rand() % 100) < 20 ;
}

int main(){
    srand(time(NULL));
    int data[] = { 10 , 20 , 30 , 40 , 50 } ;
    int frame_size = sizeof(data)/sizeof(data[0]);
    State currentState ;
    int seq_no =0 ;
    for(int i=0 ; i< frame_size ; i++){
        Frame f ;
        f.data = data[i];
        f.seq_no = seq_no ;
        currentState = IDLE ;
        while(1){
            if(currentState == IDLE){
                printf("SENDING FRAME : Data = %d , Seq_no = %d \n" ,
                f.data , f.seq_no);
                if(isError()){
                 printf("ERROR IN SENDING FRAME TO RECEIVER : Data = %d , Seq_no = %d  \n" ,
                f.data , f.seq_no);  
                }
                else{
               printf("FRAME IS SENT SUCCESSFULLY :Data = %d ,Seq_no = %d \n" , f.data , f.seq_no);
               currentState = WAITING_FOR_ACK;
                }
            }
            else if( currentState == WAITING_FOR_ACK){
              sleep(TIMEOUT);
              if(isError()){
                  printf("ACK IS LOST WHILE SENDING :Data = %d , Seq_No = %d \n "  , f.data , f.seq_no);
                  currentState = IDLE ;
              }
              else{
                  printf(" ACK IS SENT SUCCESSFULLY:  Seq_no = %d \n" ,
                 f.seq_no);
                 seq_no = 1 - seq_no;
                 break;
              }
            }
        }
    }
    printf("ALL FRAMES ARE SENT SUCCESSFYLLY \n");
    return 0;
}