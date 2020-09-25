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
	cout << "     R2*R3" << endl;
	cout << "R_b=-----------" << endl;
	cout << "    R2+R3+R5" << endl;
	float r_b = (r[1] * r[2]) / (r[1] + r[2] + r[4]);
	cout << "R_b=" << r_b << endl << endl;

	cout << "     R3*R5" << endl;
	cout << "R_ñ=-----------" << endl;
	cout << "    R2+R3+R5" << endl;
	float r_c = (r[2] * r[4]) / (r[1] + r[2] + r[4]);
	cout << "R_c=" << r_c << endl << endl;

	cout << "     R2*R5" << endl;
	cout << "R_b=-----------" << endl;
	cout << "     R2+R3+R5" << endl;
	float r_d = (r[1] * r[4]) / (r[1] + r[2] + r[4]);
	cout << "R_d=" << r_d << endl << endl;

	cout << "           (R_d+R4)*(R_c+R6) " << endl;
	cout << "R_vn=R_b+ -------------------" << endl;
	cout << "            R_d+R4+R_c+R6    " << endl;
	r[6] = r_b + ((r_d + r[3]) * (r_c + r[5])) / (r_d + r[3] + r_c + r[5]);
	cout << "R_vn=" << r[6] << endl << endl;

	cout << "      E3-E2      E4-E6     E5  " << endl;
	cout << "     -------  + ------- - ---- " << endl;
	cout << "      R2+R3      R4+R6     R5  " << endl;
	cout << "U_dc=--------------------------" << endl;
	cout << "         1        1       1    " << endl;
	cout << "      ------- + ---- + ------- " << endl;
	cout << "       R2+R3     R5     R4+R6  " << endl;
	float U_dc = ((e[2] - e[1]) / (r[1] + r[2]) + (e[3] - e[5]) / (r[3] + r[5])-(e[4]/r[4])) / ((1 / (r[1] + r[2])) + (1 / r[4]) + (1 / (r[3] + r[5])));
	cout << "U_dc=" << U_dc << endl << endl;

	cout << "     E4-E6-U_dc " << endl;
	cout << "I_a=------------" << endl;
	cout << "        R4+R6   " << endl;
	float I_a = (e[3] - e[5] - U_dc) / (r[3] + r[5]);
	cout << "I_a=" << I_a << endl << endl;

	cout << "     U_dc+E2-E3 " << endl;
	cout << "I_a=------------" << endl;
	cout << "        R2+R3   " << endl;
	float I_b = (U_dc + e[1] - e[2]) / (r[1] + r[2]);
	cout << "Current I_b=" << I_b << endl << endl;

	cout << "U_xx=E1-E4+R2*I_b+R4*I_a" << endl;
	float U_xx = e[0] - e[3] + r[1] * I_b + r[3] * I_a;
	cout << "U_xx=" << U_xx << endl << endl;

	cout << "      U_xx   " << endl;
	cout << "I1=----------" << endl;
	cout << "     R1+R_vn " << endl;
	cout << "I1=" << U_xx / (r[0] + r[6]) << endl << endl;
	cout << "Press Enter";
	cin.ignore(1,'\n');
	cin.get();
}