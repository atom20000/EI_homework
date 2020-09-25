#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	float r[7];
	float e[7];
	for (int i = 0; i < 6; i++) {
		cout << "Enter the resistance R" << i + 1 << endl;
		cin >> r[i];
	}
	for (int i = 0; i < 6; i++) {
		cout << "Enter the EMF E" << i + 1 << endl;
		cin >> e[i];
	}
	float r_b = (r[1] * r[2]) / (r[1] + r[2] + r[4]);
	float r_c = (r[2] * r[4]) / (r[1] + r[2] + r[4]);
	float r_d = (r[1] * r[4]) / (r[1] + r[2] + r[4]);
	r[6] = r_b + ((r_d + r[3]) * (r_c + r[5])) / (r_d + r[3] + r_c + r[5]);
	float U_dc = ((e[2] - e[1]) / (r[1] + r[2]) + (e[3] - e[5]) / (r[3] + r[5])) / ((1 / (r[1] + r[2])) + (1 / r[4]) + (1 / (r[3] + r[5])));
	float I_a = (e[3] - e[5] - U_dc) / (r[3] + r[5]);
	float I_b = (U_dc + e[1] - e[2]) / (r[1] + r[2]);
	float U_xx = e[0] - e[3] + r[1] * I_b + r[3] * I_a;
	cout << "Current I1=" << U_xx / (r[0] + r[6]) << endl;
	cin.ignore(1,'\n');
	cin.get();
}