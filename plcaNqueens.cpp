#include<iostream>
#define N 25

using namespace std;

bool slopeOf(int x1, int y1, int x2, int y2){
	int res1 = y2 > y1 ? y2 - y1 : y1 - y2;
	int res2 = x2 > x1 ? x2 - x1 : x1 - x2;
	if(res1 == res2)	return true;
	return false;
}

bool isSafe(int arr[][N], int i, int j){
	if(i > N-1 || j > N-1)	return false;
	
	for(int h = 0 ; h < N ; h++)
			if(arr[i][h] == 1)	return false;

	for(int k = 0 ; k < N ; k++)
		for(int h = 0 ; h < N ; h++)
			if(arr[k][h] == 1)
				if(slopeOf(k,h,i,j)) return false;

	return true;
}

bool placeNQueens(int arr[][N], int count){
	if(count >= N)
		return true;
	for(int k = 0 ; k < N ; k++){
		if(isSafe(arr, k, count)){
			arr[k][count] = 1;
			if(placeNQueens(arr, count + 1))
				return true;
			arr[k][count] = 0;
		}
	}
		
	return false;
}

void print(int arr[][N]){
	printf("Final placement of Queens : \n");
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;	
	}
}

int main(){
	int arr[N][N] = {0};
	if(placeNQueens(arr,0))
		print(arr);
	else{
		cout<<"no solution";
		print(arr);	
	}
	return 0;
}
