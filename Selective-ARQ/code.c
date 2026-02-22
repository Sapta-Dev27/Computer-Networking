#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int total_frames , base = 1 , window_size ;
    printf("Enter the size of the window : \n");
    scanf("%d" , &window_size);
    printf("Enter the total no of frames : \n");
    scanf("%d" , &total_frames);
    int ack ;
    int acked[100] = {0};
    while(base <= total_frames){
         printf("SENDER : SENDING FRAMES ........ \n");
        for(int i= base ; i < base + window_size && i <= total_frames ; i++){
             if(acked[i] == 0){
                printf("SENDER : SENDING FRAME NO : %d \n",i);
                ack = rand() % 2 ;
                if( ack == 1){
                    printf("RECEIVER:Received Frame %d and acknowledged successfully.\n" ,i);
                    acked[i]=1;
                }
                else{
                    printf("RECEIVER : Failed to acknowledge frame No : %d \n" , i);
                }
                sleep(1);
            }
        }
        while (  base <= total_frames && acked[base] == 1){
            base ++ ;
        }
    }
    printf("ALL FRAMES ARE SENT SUCCESSFULLY");
    return 0;
}