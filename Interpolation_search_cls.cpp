import java.util.*;

 public class Main {
    public static int interpolation_search(int arr[],int target,int high, int low) {

     int pos;
     
     if(low <=high && arr[low]<=target && arr[high]>=high){
       pos = low + (target -arr[low])/(arr[high]-arr[low]*(high-low));
          if(arr[pos]==target)  return pos;
          if (arr[pos]<target) return interpolation_search(arr,target, high , pos+1);
          if (arr[pos]>target) return interpolation_search(arr,target, pos-1 , low);
     }
       return -1;
  }
      public static void main(String []args ){
             int arr[]={2,4,6,8,10};
             int low = 0, high =arr.length-1,target = 8;
            int ans = interpolation_search(arr, target,high,low);
            if(ans!=-1){
              System.out.println(ans);
            }
             else{
               System.out.println("NO");
             }
      }
}

// interpolation search in c 
// #include <stdio.h>
// int solve(int arr[],int size,int target){
//   int low = 0, high= size-1;
  
//   while(low<=high&&arr[low]<=target && arr[high]>=target){
//     int pos = low + (target -arr[low])/(arr[high]-arr[low]*(high-low));
//     if(arr[pos]==target) return pos;
//     else if(arr[pos]<target){
//       low = pos+1;
//     }
//     else {
//       high  = pos-1;
//     }
//   }
// return -1;
// }
// int main()
// {
//   int arr[5]={2,4,6,8,10};
//   int size = sizeof(arr)/sizeof(4);
//   int target= 8;
// int ans=  solve(arr,size,target);
// if(ans!=-1){
//   printf("%d ",ans);
// }
// else{
//   printf("No");
// }
// }

