#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(){
    int window_size , total_frames ;
    int current_frame = 1 ;
    int ack  , i ;
    printf("Enter the size of the window :");
    scanf("%d" , & window_size);
    printf("Enter the total no of frames :");
    scanf("%d" , &total_frames);
    while( current_frame <= total_frames){
        int transmitted = 0 ;
        for(int i= current_frame ; i < current_frame + window_size && i <= total_frames ;
        i++){
            transmitted ++ ;
            printf("SENDER : SENDING FRAME NO : %d \n" , i);
        }
        ack = rand() % 2 ;
        if( ack == 1){
            printf("RECEIVER : RECEIVED FRAMES  ACKNOWLEDGED UPTO %d \n" , current_frame);
            current_frame ++ ;
        }
        else {
            printf("RECEIVER : FAILED TO RECEIVE FRAME'S ACKNOWLEDGEMENT %d \n" , current_frame);
            printf("SENDER : RETRANSMITTING FRAMES FROM %d \n" , current_frame);
        }
    }
    printf("ALL THE FRAMES ARE ACKNOWLEDGED SUCCESSFULLY \n");
    return 0;
}