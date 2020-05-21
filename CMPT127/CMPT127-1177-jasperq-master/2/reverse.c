void reverse(int arr[], unsigned int len){
	int old_arr[len];
	unsigned int count = 0;
	for (int x = 0; x < len; x++){
		old_arr[x] = arr[x];
	}
	for(int i = len-1; i >= 0; i--){
		arr[count] = old_arr[i];
		count++;
	}
}
