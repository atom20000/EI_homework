#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	float r[7];
	float e[7];
	for (int i = 0; i < 6; i++) {
		cout << "R" << i + 1 << "=";
		cin >> r[i];
	}
	cout << "\n\n";
	for (int i = 0; i < 6; i++) {
		cout << "E" << i + 1 << "=";
		cin >> e[i];
	}
	float r_b = (r[1] * r[2]) / (r[1] + r[2] + r[4]);
	cout << "Resistance R_b=" << r_b << endl << endl;
	float r_c = (r[2] * r[4]) / (r[1] + r[2] + r[4]);
	cout << "Resistance R_c=" << r_b << endl << endl;
	float r_d = (r[1] * r[4]) / (r[1] + r[2] + r[4]);
	cout << "Resistance R_d=" << r_b << endl << endl;
	r[6] = r_b + ((r_d + r[3]) * (r_c + r[5])) / (r_d + r[3] + r_c + r[5]);
	cout << "Resistance R_vn=" << r[6] << endl << endl;
	float U_dc = ((e[2] - e[1]) / (r[1] + r[2]) + (e[3] - e[5]) / (r[3] + r[5])-(e[4]/r[4])) / ((1 / (r[1] + r[2])) + (1 / r[4]) + (1 / (r[3] + r[5])));
	cout << "Voltage U_dc=" << U_dc << endl << endl;
	float I_a = (e[3] - e[5] - U_dc) / (r[3] + r[5]);
	cout << "Current I_a=" << I_a << endl << endl;
	float I_b = (U_dc + e[1] - e[2]) / (r[1] + r[2]);
	cout << "Current I_b=" << I_b << endl << endl;
	float U_xx = e[0] - e[3] + r[1] * I_b + r[3] * I_a;
	cout << "Voltage U_xx=" << U_xx << endl << endl;
	cout << "Current I1=" << U_xx / (r[0] + r[6]) << endl << endl;
	cout << "Press Enter";
	cin.ignore(1,'\n');
	cin.get();
}