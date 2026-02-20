#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void send_Frames(int start , int window , int total_frames){
    printf("SENDING FRAMES .....\n");
    for(int i= start ; i < start + window && i < total_frames ; i++){
        printf("Frames %d" , i);
        printf("\n");
    }
}

int receive_ack( int start , int window  , int total_frames){
    int index = rand() % window ;
    int ack = start + index ;
    if( ack >= total_frames){
        ack = total_frames - 1;
    }
    printf("ACK IS ACKNOWLEDGED UPTO FRAME %d \n" , ack);
    return ack + 1;
}

int main(){
    srand(time(NULL));
    int frames , window_size;
    printf("Enter the no of frames :  \n");
    scanf("%d" , &frames);
    printf("Enter the size of the window : \n");
    scanf("%d" , &window_size);
    int base  =0 ;
    while( base < frames){
       int  window = window_size;
       if( base + window > frames){
           window = frames - base ;
       }
       send_Frames(base , window , frames);
       int ack = receive_ack(base , window , frames);
       if( ack == base + window){
           printf("ALL FRAMES TILL NOW ARE ACKNOWLEDGED \n");
           base = ack ;
       }
       else {
           printf("THERE IS AN ERROR . not all the frames are acknowledged \n");
           base = ack ;
       }
    }
    printf("ALL FRAMES ACKNOWLEDGED SUCCESSFULLY");
    return 0;
}