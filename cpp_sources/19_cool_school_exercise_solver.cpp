//this one works just fine, trust me!

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int Average(vector<int> sych){
	int sum = accumulate(sych.begin(), sych.end(), 0);
	int len = sych.size();
	int average = sum/len;
	return average;
}

int main(){
	for(int a = 0; a < 50; a++){
		for(int b = 0; b < 50; b++){
			for(int c = 0; c < 50; c++){
				for(int d = 0; d < 50; d++){
					for(int e = 0; e < 50; e++){
						vector<int> arbuz = {a, b, c, d, e};
						sort(arbuz.begin(), arbuz.end());
						int average = Average(arbuz);

						if(arbuz[3] == average){
							cout << "a) [ ";
							for(int i = 0; i <= arbuz.size() -1; i++){
								cout << arbuz[i] << " ";
							}
							cout << "] " << arbuz[3] << endl;
						}

						if(arbuz[2] == average){
							cout << "b) [ ";
							for(int i = 0; i <= arbuz.size() - 1; i++){
								cout << arbuz[i] << " ";
							}
							cout << "] " << arbuz[2] << endl;
						}
					}
				}
			}
		}
	}
}
