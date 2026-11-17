#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1566483945621839879) {
   out_1566483945621839879[0] = delta_x[0] + nom_x[0];
   out_1566483945621839879[1] = delta_x[1] + nom_x[1];
   out_1566483945621839879[2] = delta_x[2] + nom_x[2];
   out_1566483945621839879[3] = delta_x[3] + nom_x[3];
   out_1566483945621839879[4] = delta_x[4] + nom_x[4];
   out_1566483945621839879[5] = delta_x[5] + nom_x[5];
   out_1566483945621839879[6] = delta_x[6] + nom_x[6];
   out_1566483945621839879[7] = delta_x[7] + nom_x[7];
   out_1566483945621839879[8] = delta_x[8] + nom_x[8];
   out_1566483945621839879[9] = delta_x[9] + nom_x[9];
   out_1566483945621839879[10] = delta_x[10] + nom_x[10];
   out_1566483945621839879[11] = delta_x[11] + nom_x[11];
   out_1566483945621839879[12] = delta_x[12] + nom_x[12];
   out_1566483945621839879[13] = delta_x[13] + nom_x[13];
   out_1566483945621839879[14] = delta_x[14] + nom_x[14];
   out_1566483945621839879[15] = delta_x[15] + nom_x[15];
   out_1566483945621839879[16] = delta_x[16] + nom_x[16];
   out_1566483945621839879[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5680128566882367357) {
   out_5680128566882367357[0] = -nom_x[0] + true_x[0];
   out_5680128566882367357[1] = -nom_x[1] + true_x[1];
   out_5680128566882367357[2] = -nom_x[2] + true_x[2];
   out_5680128566882367357[3] = -nom_x[3] + true_x[3];
   out_5680128566882367357[4] = -nom_x[4] + true_x[4];
   out_5680128566882367357[5] = -nom_x[5] + true_x[5];
   out_5680128566882367357[6] = -nom_x[6] + true_x[6];
   out_5680128566882367357[7] = -nom_x[7] + true_x[7];
   out_5680128566882367357[8] = -nom_x[8] + true_x[8];
   out_5680128566882367357[9] = -nom_x[9] + true_x[9];
   out_5680128566882367357[10] = -nom_x[10] + true_x[10];
   out_5680128566882367357[11] = -nom_x[11] + true_x[11];
   out_5680128566882367357[12] = -nom_x[12] + true_x[12];
   out_5680128566882367357[13] = -nom_x[13] + true_x[13];
   out_5680128566882367357[14] = -nom_x[14] + true_x[14];
   out_5680128566882367357[15] = -nom_x[15] + true_x[15];
   out_5680128566882367357[16] = -nom_x[16] + true_x[16];
   out_5680128566882367357[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_9206521029859008689) {
   out_9206521029859008689[0] = 1.0;
   out_9206521029859008689[1] = 0.0;
   out_9206521029859008689[2] = 0.0;
   out_9206521029859008689[3] = 0.0;
   out_9206521029859008689[4] = 0.0;
   out_9206521029859008689[5] = 0.0;
   out_9206521029859008689[6] = 0.0;
   out_9206521029859008689[7] = 0.0;
   out_9206521029859008689[8] = 0.0;
   out_9206521029859008689[9] = 0.0;
   out_9206521029859008689[10] = 0.0;
   out_9206521029859008689[11] = 0.0;
   out_9206521029859008689[12] = 0.0;
   out_9206521029859008689[13] = 0.0;
   out_9206521029859008689[14] = 0.0;
   out_9206521029859008689[15] = 0.0;
   out_9206521029859008689[16] = 0.0;
   out_9206521029859008689[17] = 0.0;
   out_9206521029859008689[18] = 0.0;
   out_9206521029859008689[19] = 1.0;
   out_9206521029859008689[20] = 0.0;
   out_9206521029859008689[21] = 0.0;
   out_9206521029859008689[22] = 0.0;
   out_9206521029859008689[23] = 0.0;
   out_9206521029859008689[24] = 0.0;
   out_9206521029859008689[25] = 0.0;
   out_9206521029859008689[26] = 0.0;
   out_9206521029859008689[27] = 0.0;
   out_9206521029859008689[28] = 0.0;
   out_9206521029859008689[29] = 0.0;
   out_9206521029859008689[30] = 0.0;
   out_9206521029859008689[31] = 0.0;
   out_9206521029859008689[32] = 0.0;
   out_9206521029859008689[33] = 0.0;
   out_9206521029859008689[34] = 0.0;
   out_9206521029859008689[35] = 0.0;
   out_9206521029859008689[36] = 0.0;
   out_9206521029859008689[37] = 0.0;
   out_9206521029859008689[38] = 1.0;
   out_9206521029859008689[39] = 0.0;
   out_9206521029859008689[40] = 0.0;
   out_9206521029859008689[41] = 0.0;
   out_9206521029859008689[42] = 0.0;
   out_9206521029859008689[43] = 0.0;
   out_9206521029859008689[44] = 0.0;
   out_9206521029859008689[45] = 0.0;
   out_9206521029859008689[46] = 0.0;
   out_9206521029859008689[47] = 0.0;
   out_9206521029859008689[48] = 0.0;
   out_9206521029859008689[49] = 0.0;
   out_9206521029859008689[50] = 0.0;
   out_9206521029859008689[51] = 0.0;
   out_9206521029859008689[52] = 0.0;
   out_9206521029859008689[53] = 0.0;
   out_9206521029859008689[54] = 0.0;
   out_9206521029859008689[55] = 0.0;
   out_9206521029859008689[56] = 0.0;
   out_9206521029859008689[57] = 1.0;
   out_9206521029859008689[58] = 0.0;
   out_9206521029859008689[59] = 0.0;
   out_9206521029859008689[60] = 0.0;
   out_9206521029859008689[61] = 0.0;
   out_9206521029859008689[62] = 0.0;
   out_9206521029859008689[63] = 0.0;
   out_9206521029859008689[64] = 0.0;
   out_9206521029859008689[65] = 0.0;
   out_9206521029859008689[66] = 0.0;
   out_9206521029859008689[67] = 0.0;
   out_9206521029859008689[68] = 0.0;
   out_9206521029859008689[69] = 0.0;
   out_9206521029859008689[70] = 0.0;
   out_9206521029859008689[71] = 0.0;
   out_9206521029859008689[72] = 0.0;
   out_9206521029859008689[73] = 0.0;
   out_9206521029859008689[74] = 0.0;
   out_9206521029859008689[75] = 0.0;
   out_9206521029859008689[76] = 1.0;
   out_9206521029859008689[77] = 0.0;
   out_9206521029859008689[78] = 0.0;
   out_9206521029859008689[79] = 0.0;
   out_9206521029859008689[80] = 0.0;
   out_9206521029859008689[81] = 0.0;
   out_9206521029859008689[82] = 0.0;
   out_9206521029859008689[83] = 0.0;
   out_9206521029859008689[84] = 0.0;
   out_9206521029859008689[85] = 0.0;
   out_9206521029859008689[86] = 0.0;
   out_9206521029859008689[87] = 0.0;
   out_9206521029859008689[88] = 0.0;
   out_9206521029859008689[89] = 0.0;
   out_9206521029859008689[90] = 0.0;
   out_9206521029859008689[91] = 0.0;
   out_9206521029859008689[92] = 0.0;
   out_9206521029859008689[93] = 0.0;
   out_9206521029859008689[94] = 0.0;
   out_9206521029859008689[95] = 1.0;
   out_9206521029859008689[96] = 0.0;
   out_9206521029859008689[97] = 0.0;
   out_9206521029859008689[98] = 0.0;
   out_9206521029859008689[99] = 0.0;
   out_9206521029859008689[100] = 0.0;
   out_9206521029859008689[101] = 0.0;
   out_9206521029859008689[102] = 0.0;
   out_9206521029859008689[103] = 0.0;
   out_9206521029859008689[104] = 0.0;
   out_9206521029859008689[105] = 0.0;
   out_9206521029859008689[106] = 0.0;
   out_9206521029859008689[107] = 0.0;
   out_9206521029859008689[108] = 0.0;
   out_9206521029859008689[109] = 0.0;
   out_9206521029859008689[110] = 0.0;
   out_9206521029859008689[111] = 0.0;
   out_9206521029859008689[112] = 0.0;
   out_9206521029859008689[113] = 0.0;
   out_9206521029859008689[114] = 1.0;
   out_9206521029859008689[115] = 0.0;
   out_9206521029859008689[116] = 0.0;
   out_9206521029859008689[117] = 0.0;
   out_9206521029859008689[118] = 0.0;
   out_9206521029859008689[119] = 0.0;
   out_9206521029859008689[120] = 0.0;
   out_9206521029859008689[121] = 0.0;
   out_9206521029859008689[122] = 0.0;
   out_9206521029859008689[123] = 0.0;
   out_9206521029859008689[124] = 0.0;
   out_9206521029859008689[125] = 0.0;
   out_9206521029859008689[126] = 0.0;
   out_9206521029859008689[127] = 0.0;
   out_9206521029859008689[128] = 0.0;
   out_9206521029859008689[129] = 0.0;
   out_9206521029859008689[130] = 0.0;
   out_9206521029859008689[131] = 0.0;
   out_9206521029859008689[132] = 0.0;
   out_9206521029859008689[133] = 1.0;
   out_9206521029859008689[134] = 0.0;
   out_9206521029859008689[135] = 0.0;
   out_9206521029859008689[136] = 0.0;
   out_9206521029859008689[137] = 0.0;
   out_9206521029859008689[138] = 0.0;
   out_9206521029859008689[139] = 0.0;
   out_9206521029859008689[140] = 0.0;
   out_9206521029859008689[141] = 0.0;
   out_9206521029859008689[142] = 0.0;
   out_9206521029859008689[143] = 0.0;
   out_9206521029859008689[144] = 0.0;
   out_9206521029859008689[145] = 0.0;
   out_9206521029859008689[146] = 0.0;
   out_9206521029859008689[147] = 0.0;
   out_9206521029859008689[148] = 0.0;
   out_9206521029859008689[149] = 0.0;
   out_9206521029859008689[150] = 0.0;
   out_9206521029859008689[151] = 0.0;
   out_9206521029859008689[152] = 1.0;
   out_9206521029859008689[153] = 0.0;
   out_9206521029859008689[154] = 0.0;
   out_9206521029859008689[155] = 0.0;
   out_9206521029859008689[156] = 0.0;
   out_9206521029859008689[157] = 0.0;
   out_9206521029859008689[158] = 0.0;
   out_9206521029859008689[159] = 0.0;
   out_9206521029859008689[160] = 0.0;
   out_9206521029859008689[161] = 0.0;
   out_9206521029859008689[162] = 0.0;
   out_9206521029859008689[163] = 0.0;
   out_9206521029859008689[164] = 0.0;
   out_9206521029859008689[165] = 0.0;
   out_9206521029859008689[166] = 0.0;
   out_9206521029859008689[167] = 0.0;
   out_9206521029859008689[168] = 0.0;
   out_9206521029859008689[169] = 0.0;
   out_9206521029859008689[170] = 0.0;
   out_9206521029859008689[171] = 1.0;
   out_9206521029859008689[172] = 0.0;
   out_9206521029859008689[173] = 0.0;
   out_9206521029859008689[174] = 0.0;
   out_9206521029859008689[175] = 0.0;
   out_9206521029859008689[176] = 0.0;
   out_9206521029859008689[177] = 0.0;
   out_9206521029859008689[178] = 0.0;
   out_9206521029859008689[179] = 0.0;
   out_9206521029859008689[180] = 0.0;
   out_9206521029859008689[181] = 0.0;
   out_9206521029859008689[182] = 0.0;
   out_9206521029859008689[183] = 0.0;
   out_9206521029859008689[184] = 0.0;
   out_9206521029859008689[185] = 0.0;
   out_9206521029859008689[186] = 0.0;
   out_9206521029859008689[187] = 0.0;
   out_9206521029859008689[188] = 0.0;
   out_9206521029859008689[189] = 0.0;
   out_9206521029859008689[190] = 1.0;
   out_9206521029859008689[191] = 0.0;
   out_9206521029859008689[192] = 0.0;
   out_9206521029859008689[193] = 0.0;
   out_9206521029859008689[194] = 0.0;
   out_9206521029859008689[195] = 0.0;
   out_9206521029859008689[196] = 0.0;
   out_9206521029859008689[197] = 0.0;
   out_9206521029859008689[198] = 0.0;
   out_9206521029859008689[199] = 0.0;
   out_9206521029859008689[200] = 0.0;
   out_9206521029859008689[201] = 0.0;
   out_9206521029859008689[202] = 0.0;
   out_9206521029859008689[203] = 0.0;
   out_9206521029859008689[204] = 0.0;
   out_9206521029859008689[205] = 0.0;
   out_9206521029859008689[206] = 0.0;
   out_9206521029859008689[207] = 0.0;
   out_9206521029859008689[208] = 0.0;
   out_9206521029859008689[209] = 1.0;
   out_9206521029859008689[210] = 0.0;
   out_9206521029859008689[211] = 0.0;
   out_9206521029859008689[212] = 0.0;
   out_9206521029859008689[213] = 0.0;
   out_9206521029859008689[214] = 0.0;
   out_9206521029859008689[215] = 0.0;
   out_9206521029859008689[216] = 0.0;
   out_9206521029859008689[217] = 0.0;
   out_9206521029859008689[218] = 0.0;
   out_9206521029859008689[219] = 0.0;
   out_9206521029859008689[220] = 0.0;
   out_9206521029859008689[221] = 0.0;
   out_9206521029859008689[222] = 0.0;
   out_9206521029859008689[223] = 0.0;
   out_9206521029859008689[224] = 0.0;
   out_9206521029859008689[225] = 0.0;
   out_9206521029859008689[226] = 0.0;
   out_9206521029859008689[227] = 0.0;
   out_9206521029859008689[228] = 1.0;
   out_9206521029859008689[229] = 0.0;
   out_9206521029859008689[230] = 0.0;
   out_9206521029859008689[231] = 0.0;
   out_9206521029859008689[232] = 0.0;
   out_9206521029859008689[233] = 0.0;
   out_9206521029859008689[234] = 0.0;
   out_9206521029859008689[235] = 0.0;
   out_9206521029859008689[236] = 0.0;
   out_9206521029859008689[237] = 0.0;
   out_9206521029859008689[238] = 0.0;
   out_9206521029859008689[239] = 0.0;
   out_9206521029859008689[240] = 0.0;
   out_9206521029859008689[241] = 0.0;
   out_9206521029859008689[242] = 0.0;
   out_9206521029859008689[243] = 0.0;
   out_9206521029859008689[244] = 0.0;
   out_9206521029859008689[245] = 0.0;
   out_9206521029859008689[246] = 0.0;
   out_9206521029859008689[247] = 1.0;
   out_9206521029859008689[248] = 0.0;
   out_9206521029859008689[249] = 0.0;
   out_9206521029859008689[250] = 0.0;
   out_9206521029859008689[251] = 0.0;
   out_9206521029859008689[252] = 0.0;
   out_9206521029859008689[253] = 0.0;
   out_9206521029859008689[254] = 0.0;
   out_9206521029859008689[255] = 0.0;
   out_9206521029859008689[256] = 0.0;
   out_9206521029859008689[257] = 0.0;
   out_9206521029859008689[258] = 0.0;
   out_9206521029859008689[259] = 0.0;
   out_9206521029859008689[260] = 0.0;
   out_9206521029859008689[261] = 0.0;
   out_9206521029859008689[262] = 0.0;
   out_9206521029859008689[263] = 0.0;
   out_9206521029859008689[264] = 0.0;
   out_9206521029859008689[265] = 0.0;
   out_9206521029859008689[266] = 1.0;
   out_9206521029859008689[267] = 0.0;
   out_9206521029859008689[268] = 0.0;
   out_9206521029859008689[269] = 0.0;
   out_9206521029859008689[270] = 0.0;
   out_9206521029859008689[271] = 0.0;
   out_9206521029859008689[272] = 0.0;
   out_9206521029859008689[273] = 0.0;
   out_9206521029859008689[274] = 0.0;
   out_9206521029859008689[275] = 0.0;
   out_9206521029859008689[276] = 0.0;
   out_9206521029859008689[277] = 0.0;
   out_9206521029859008689[278] = 0.0;
   out_9206521029859008689[279] = 0.0;
   out_9206521029859008689[280] = 0.0;
   out_9206521029859008689[281] = 0.0;
   out_9206521029859008689[282] = 0.0;
   out_9206521029859008689[283] = 0.0;
   out_9206521029859008689[284] = 0.0;
   out_9206521029859008689[285] = 1.0;
   out_9206521029859008689[286] = 0.0;
   out_9206521029859008689[287] = 0.0;
   out_9206521029859008689[288] = 0.0;
   out_9206521029859008689[289] = 0.0;
   out_9206521029859008689[290] = 0.0;
   out_9206521029859008689[291] = 0.0;
   out_9206521029859008689[292] = 0.0;
   out_9206521029859008689[293] = 0.0;
   out_9206521029859008689[294] = 0.0;
   out_9206521029859008689[295] = 0.0;
   out_9206521029859008689[296] = 0.0;
   out_9206521029859008689[297] = 0.0;
   out_9206521029859008689[298] = 0.0;
   out_9206521029859008689[299] = 0.0;
   out_9206521029859008689[300] = 0.0;
   out_9206521029859008689[301] = 0.0;
   out_9206521029859008689[302] = 0.0;
   out_9206521029859008689[303] = 0.0;
   out_9206521029859008689[304] = 1.0;
   out_9206521029859008689[305] = 0.0;
   out_9206521029859008689[306] = 0.0;
   out_9206521029859008689[307] = 0.0;
   out_9206521029859008689[308] = 0.0;
   out_9206521029859008689[309] = 0.0;
   out_9206521029859008689[310] = 0.0;
   out_9206521029859008689[311] = 0.0;
   out_9206521029859008689[312] = 0.0;
   out_9206521029859008689[313] = 0.0;
   out_9206521029859008689[314] = 0.0;
   out_9206521029859008689[315] = 0.0;
   out_9206521029859008689[316] = 0.0;
   out_9206521029859008689[317] = 0.0;
   out_9206521029859008689[318] = 0.0;
   out_9206521029859008689[319] = 0.0;
   out_9206521029859008689[320] = 0.0;
   out_9206521029859008689[321] = 0.0;
   out_9206521029859008689[322] = 0.0;
   out_9206521029859008689[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6263565860580378794) {
   out_6263565860580378794[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6263565860580378794[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6263565860580378794[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6263565860580378794[3] = dt*state[12] + state[3];
   out_6263565860580378794[4] = dt*state[13] + state[4];
   out_6263565860580378794[5] = dt*state[14] + state[5];
   out_6263565860580378794[6] = state[6];
   out_6263565860580378794[7] = state[7];
   out_6263565860580378794[8] = state[8];
   out_6263565860580378794[9] = state[9];
   out_6263565860580378794[10] = state[10];
   out_6263565860580378794[11] = state[11];
   out_6263565860580378794[12] = state[12];
   out_6263565860580378794[13] = state[13];
   out_6263565860580378794[14] = state[14];
   out_6263565860580378794[15] = state[15];
   out_6263565860580378794[16] = state[16];
   out_6263565860580378794[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5475119388677115833) {
   out_5475119388677115833[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5475119388677115833[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5475119388677115833[2] = 0;
   out_5475119388677115833[3] = 0;
   out_5475119388677115833[4] = 0;
   out_5475119388677115833[5] = 0;
   out_5475119388677115833[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5475119388677115833[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5475119388677115833[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5475119388677115833[9] = 0;
   out_5475119388677115833[10] = 0;
   out_5475119388677115833[11] = 0;
   out_5475119388677115833[12] = 0;
   out_5475119388677115833[13] = 0;
   out_5475119388677115833[14] = 0;
   out_5475119388677115833[15] = 0;
   out_5475119388677115833[16] = 0;
   out_5475119388677115833[17] = 0;
   out_5475119388677115833[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5475119388677115833[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5475119388677115833[20] = 0;
   out_5475119388677115833[21] = 0;
   out_5475119388677115833[22] = 0;
   out_5475119388677115833[23] = 0;
   out_5475119388677115833[24] = 0;
   out_5475119388677115833[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5475119388677115833[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5475119388677115833[27] = 0;
   out_5475119388677115833[28] = 0;
   out_5475119388677115833[29] = 0;
   out_5475119388677115833[30] = 0;
   out_5475119388677115833[31] = 0;
   out_5475119388677115833[32] = 0;
   out_5475119388677115833[33] = 0;
   out_5475119388677115833[34] = 0;
   out_5475119388677115833[35] = 0;
   out_5475119388677115833[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5475119388677115833[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5475119388677115833[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5475119388677115833[39] = 0;
   out_5475119388677115833[40] = 0;
   out_5475119388677115833[41] = 0;
   out_5475119388677115833[42] = 0;
   out_5475119388677115833[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5475119388677115833[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5475119388677115833[45] = 0;
   out_5475119388677115833[46] = 0;
   out_5475119388677115833[47] = 0;
   out_5475119388677115833[48] = 0;
   out_5475119388677115833[49] = 0;
   out_5475119388677115833[50] = 0;
   out_5475119388677115833[51] = 0;
   out_5475119388677115833[52] = 0;
   out_5475119388677115833[53] = 0;
   out_5475119388677115833[54] = 0;
   out_5475119388677115833[55] = 0;
   out_5475119388677115833[56] = 0;
   out_5475119388677115833[57] = 1;
   out_5475119388677115833[58] = 0;
   out_5475119388677115833[59] = 0;
   out_5475119388677115833[60] = 0;
   out_5475119388677115833[61] = 0;
   out_5475119388677115833[62] = 0;
   out_5475119388677115833[63] = 0;
   out_5475119388677115833[64] = 0;
   out_5475119388677115833[65] = 0;
   out_5475119388677115833[66] = dt;
   out_5475119388677115833[67] = 0;
   out_5475119388677115833[68] = 0;
   out_5475119388677115833[69] = 0;
   out_5475119388677115833[70] = 0;
   out_5475119388677115833[71] = 0;
   out_5475119388677115833[72] = 0;
   out_5475119388677115833[73] = 0;
   out_5475119388677115833[74] = 0;
   out_5475119388677115833[75] = 0;
   out_5475119388677115833[76] = 1;
   out_5475119388677115833[77] = 0;
   out_5475119388677115833[78] = 0;
   out_5475119388677115833[79] = 0;
   out_5475119388677115833[80] = 0;
   out_5475119388677115833[81] = 0;
   out_5475119388677115833[82] = 0;
   out_5475119388677115833[83] = 0;
   out_5475119388677115833[84] = 0;
   out_5475119388677115833[85] = dt;
   out_5475119388677115833[86] = 0;
   out_5475119388677115833[87] = 0;
   out_5475119388677115833[88] = 0;
   out_5475119388677115833[89] = 0;
   out_5475119388677115833[90] = 0;
   out_5475119388677115833[91] = 0;
   out_5475119388677115833[92] = 0;
   out_5475119388677115833[93] = 0;
   out_5475119388677115833[94] = 0;
   out_5475119388677115833[95] = 1;
   out_5475119388677115833[96] = 0;
   out_5475119388677115833[97] = 0;
   out_5475119388677115833[98] = 0;
   out_5475119388677115833[99] = 0;
   out_5475119388677115833[100] = 0;
   out_5475119388677115833[101] = 0;
   out_5475119388677115833[102] = 0;
   out_5475119388677115833[103] = 0;
   out_5475119388677115833[104] = dt;
   out_5475119388677115833[105] = 0;
   out_5475119388677115833[106] = 0;
   out_5475119388677115833[107] = 0;
   out_5475119388677115833[108] = 0;
   out_5475119388677115833[109] = 0;
   out_5475119388677115833[110] = 0;
   out_5475119388677115833[111] = 0;
   out_5475119388677115833[112] = 0;
   out_5475119388677115833[113] = 0;
   out_5475119388677115833[114] = 1;
   out_5475119388677115833[115] = 0;
   out_5475119388677115833[116] = 0;
   out_5475119388677115833[117] = 0;
   out_5475119388677115833[118] = 0;
   out_5475119388677115833[119] = 0;
   out_5475119388677115833[120] = 0;
   out_5475119388677115833[121] = 0;
   out_5475119388677115833[122] = 0;
   out_5475119388677115833[123] = 0;
   out_5475119388677115833[124] = 0;
   out_5475119388677115833[125] = 0;
   out_5475119388677115833[126] = 0;
   out_5475119388677115833[127] = 0;
   out_5475119388677115833[128] = 0;
   out_5475119388677115833[129] = 0;
   out_5475119388677115833[130] = 0;
   out_5475119388677115833[131] = 0;
   out_5475119388677115833[132] = 0;
   out_5475119388677115833[133] = 1;
   out_5475119388677115833[134] = 0;
   out_5475119388677115833[135] = 0;
   out_5475119388677115833[136] = 0;
   out_5475119388677115833[137] = 0;
   out_5475119388677115833[138] = 0;
   out_5475119388677115833[139] = 0;
   out_5475119388677115833[140] = 0;
   out_5475119388677115833[141] = 0;
   out_5475119388677115833[142] = 0;
   out_5475119388677115833[143] = 0;
   out_5475119388677115833[144] = 0;
   out_5475119388677115833[145] = 0;
   out_5475119388677115833[146] = 0;
   out_5475119388677115833[147] = 0;
   out_5475119388677115833[148] = 0;
   out_5475119388677115833[149] = 0;
   out_5475119388677115833[150] = 0;
   out_5475119388677115833[151] = 0;
   out_5475119388677115833[152] = 1;
   out_5475119388677115833[153] = 0;
   out_5475119388677115833[154] = 0;
   out_5475119388677115833[155] = 0;
   out_5475119388677115833[156] = 0;
   out_5475119388677115833[157] = 0;
   out_5475119388677115833[158] = 0;
   out_5475119388677115833[159] = 0;
   out_5475119388677115833[160] = 0;
   out_5475119388677115833[161] = 0;
   out_5475119388677115833[162] = 0;
   out_5475119388677115833[163] = 0;
   out_5475119388677115833[164] = 0;
   out_5475119388677115833[165] = 0;
   out_5475119388677115833[166] = 0;
   out_5475119388677115833[167] = 0;
   out_5475119388677115833[168] = 0;
   out_5475119388677115833[169] = 0;
   out_5475119388677115833[170] = 0;
   out_5475119388677115833[171] = 1;
   out_5475119388677115833[172] = 0;
   out_5475119388677115833[173] = 0;
   out_5475119388677115833[174] = 0;
   out_5475119388677115833[175] = 0;
   out_5475119388677115833[176] = 0;
   out_5475119388677115833[177] = 0;
   out_5475119388677115833[178] = 0;
   out_5475119388677115833[179] = 0;
   out_5475119388677115833[180] = 0;
   out_5475119388677115833[181] = 0;
   out_5475119388677115833[182] = 0;
   out_5475119388677115833[183] = 0;
   out_5475119388677115833[184] = 0;
   out_5475119388677115833[185] = 0;
   out_5475119388677115833[186] = 0;
   out_5475119388677115833[187] = 0;
   out_5475119388677115833[188] = 0;
   out_5475119388677115833[189] = 0;
   out_5475119388677115833[190] = 1;
   out_5475119388677115833[191] = 0;
   out_5475119388677115833[192] = 0;
   out_5475119388677115833[193] = 0;
   out_5475119388677115833[194] = 0;
   out_5475119388677115833[195] = 0;
   out_5475119388677115833[196] = 0;
   out_5475119388677115833[197] = 0;
   out_5475119388677115833[198] = 0;
   out_5475119388677115833[199] = 0;
   out_5475119388677115833[200] = 0;
   out_5475119388677115833[201] = 0;
   out_5475119388677115833[202] = 0;
   out_5475119388677115833[203] = 0;
   out_5475119388677115833[204] = 0;
   out_5475119388677115833[205] = 0;
   out_5475119388677115833[206] = 0;
   out_5475119388677115833[207] = 0;
   out_5475119388677115833[208] = 0;
   out_5475119388677115833[209] = 1;
   out_5475119388677115833[210] = 0;
   out_5475119388677115833[211] = 0;
   out_5475119388677115833[212] = 0;
   out_5475119388677115833[213] = 0;
   out_5475119388677115833[214] = 0;
   out_5475119388677115833[215] = 0;
   out_5475119388677115833[216] = 0;
   out_5475119388677115833[217] = 0;
   out_5475119388677115833[218] = 0;
   out_5475119388677115833[219] = 0;
   out_5475119388677115833[220] = 0;
   out_5475119388677115833[221] = 0;
   out_5475119388677115833[222] = 0;
   out_5475119388677115833[223] = 0;
   out_5475119388677115833[224] = 0;
   out_5475119388677115833[225] = 0;
   out_5475119388677115833[226] = 0;
   out_5475119388677115833[227] = 0;
   out_5475119388677115833[228] = 1;
   out_5475119388677115833[229] = 0;
   out_5475119388677115833[230] = 0;
   out_5475119388677115833[231] = 0;
   out_5475119388677115833[232] = 0;
   out_5475119388677115833[233] = 0;
   out_5475119388677115833[234] = 0;
   out_5475119388677115833[235] = 0;
   out_5475119388677115833[236] = 0;
   out_5475119388677115833[237] = 0;
   out_5475119388677115833[238] = 0;
   out_5475119388677115833[239] = 0;
   out_5475119388677115833[240] = 0;
   out_5475119388677115833[241] = 0;
   out_5475119388677115833[242] = 0;
   out_5475119388677115833[243] = 0;
   out_5475119388677115833[244] = 0;
   out_5475119388677115833[245] = 0;
   out_5475119388677115833[246] = 0;
   out_5475119388677115833[247] = 1;
   out_5475119388677115833[248] = 0;
   out_5475119388677115833[249] = 0;
   out_5475119388677115833[250] = 0;
   out_5475119388677115833[251] = 0;
   out_5475119388677115833[252] = 0;
   out_5475119388677115833[253] = 0;
   out_5475119388677115833[254] = 0;
   out_5475119388677115833[255] = 0;
   out_5475119388677115833[256] = 0;
   out_5475119388677115833[257] = 0;
   out_5475119388677115833[258] = 0;
   out_5475119388677115833[259] = 0;
   out_5475119388677115833[260] = 0;
   out_5475119388677115833[261] = 0;
   out_5475119388677115833[262] = 0;
   out_5475119388677115833[263] = 0;
   out_5475119388677115833[264] = 0;
   out_5475119388677115833[265] = 0;
   out_5475119388677115833[266] = 1;
   out_5475119388677115833[267] = 0;
   out_5475119388677115833[268] = 0;
   out_5475119388677115833[269] = 0;
   out_5475119388677115833[270] = 0;
   out_5475119388677115833[271] = 0;
   out_5475119388677115833[272] = 0;
   out_5475119388677115833[273] = 0;
   out_5475119388677115833[274] = 0;
   out_5475119388677115833[275] = 0;
   out_5475119388677115833[276] = 0;
   out_5475119388677115833[277] = 0;
   out_5475119388677115833[278] = 0;
   out_5475119388677115833[279] = 0;
   out_5475119388677115833[280] = 0;
   out_5475119388677115833[281] = 0;
   out_5475119388677115833[282] = 0;
   out_5475119388677115833[283] = 0;
   out_5475119388677115833[284] = 0;
   out_5475119388677115833[285] = 1;
   out_5475119388677115833[286] = 0;
   out_5475119388677115833[287] = 0;
   out_5475119388677115833[288] = 0;
   out_5475119388677115833[289] = 0;
   out_5475119388677115833[290] = 0;
   out_5475119388677115833[291] = 0;
   out_5475119388677115833[292] = 0;
   out_5475119388677115833[293] = 0;
   out_5475119388677115833[294] = 0;
   out_5475119388677115833[295] = 0;
   out_5475119388677115833[296] = 0;
   out_5475119388677115833[297] = 0;
   out_5475119388677115833[298] = 0;
   out_5475119388677115833[299] = 0;
   out_5475119388677115833[300] = 0;
   out_5475119388677115833[301] = 0;
   out_5475119388677115833[302] = 0;
   out_5475119388677115833[303] = 0;
   out_5475119388677115833[304] = 1;
   out_5475119388677115833[305] = 0;
   out_5475119388677115833[306] = 0;
   out_5475119388677115833[307] = 0;
   out_5475119388677115833[308] = 0;
   out_5475119388677115833[309] = 0;
   out_5475119388677115833[310] = 0;
   out_5475119388677115833[311] = 0;
   out_5475119388677115833[312] = 0;
   out_5475119388677115833[313] = 0;
   out_5475119388677115833[314] = 0;
   out_5475119388677115833[315] = 0;
   out_5475119388677115833[316] = 0;
   out_5475119388677115833[317] = 0;
   out_5475119388677115833[318] = 0;
   out_5475119388677115833[319] = 0;
   out_5475119388677115833[320] = 0;
   out_5475119388677115833[321] = 0;
   out_5475119388677115833[322] = 0;
   out_5475119388677115833[323] = 1;
}
void h_4(double *state, double *unused, double *out_2784573447061806248) {
   out_2784573447061806248[0] = state[6] + state[9];
   out_2784573447061806248[1] = state[7] + state[10];
   out_2784573447061806248[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5468415834006635355) {
   out_5468415834006635355[0] = 0;
   out_5468415834006635355[1] = 0;
   out_5468415834006635355[2] = 0;
   out_5468415834006635355[3] = 0;
   out_5468415834006635355[4] = 0;
   out_5468415834006635355[5] = 0;
   out_5468415834006635355[6] = 1;
   out_5468415834006635355[7] = 0;
   out_5468415834006635355[8] = 0;
   out_5468415834006635355[9] = 1;
   out_5468415834006635355[10] = 0;
   out_5468415834006635355[11] = 0;
   out_5468415834006635355[12] = 0;
   out_5468415834006635355[13] = 0;
   out_5468415834006635355[14] = 0;
   out_5468415834006635355[15] = 0;
   out_5468415834006635355[16] = 0;
   out_5468415834006635355[17] = 0;
   out_5468415834006635355[18] = 0;
   out_5468415834006635355[19] = 0;
   out_5468415834006635355[20] = 0;
   out_5468415834006635355[21] = 0;
   out_5468415834006635355[22] = 0;
   out_5468415834006635355[23] = 0;
   out_5468415834006635355[24] = 0;
   out_5468415834006635355[25] = 1;
   out_5468415834006635355[26] = 0;
   out_5468415834006635355[27] = 0;
   out_5468415834006635355[28] = 1;
   out_5468415834006635355[29] = 0;
   out_5468415834006635355[30] = 0;
   out_5468415834006635355[31] = 0;
   out_5468415834006635355[32] = 0;
   out_5468415834006635355[33] = 0;
   out_5468415834006635355[34] = 0;
   out_5468415834006635355[35] = 0;
   out_5468415834006635355[36] = 0;
   out_5468415834006635355[37] = 0;
   out_5468415834006635355[38] = 0;
   out_5468415834006635355[39] = 0;
   out_5468415834006635355[40] = 0;
   out_5468415834006635355[41] = 0;
   out_5468415834006635355[42] = 0;
   out_5468415834006635355[43] = 0;
   out_5468415834006635355[44] = 1;
   out_5468415834006635355[45] = 0;
   out_5468415834006635355[46] = 0;
   out_5468415834006635355[47] = 1;
   out_5468415834006635355[48] = 0;
   out_5468415834006635355[49] = 0;
   out_5468415834006635355[50] = 0;
   out_5468415834006635355[51] = 0;
   out_5468415834006635355[52] = 0;
   out_5468415834006635355[53] = 0;
}
void h_10(double *state, double *unused, double *out_2001396750132265268) {
   out_2001396750132265268[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_2001396750132265268[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_2001396750132265268[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3198289938668904119) {
   out_3198289938668904119[0] = 0;
   out_3198289938668904119[1] = 9.8100000000000005*cos(state[1]);
   out_3198289938668904119[2] = 0;
   out_3198289938668904119[3] = 0;
   out_3198289938668904119[4] = -state[8];
   out_3198289938668904119[5] = state[7];
   out_3198289938668904119[6] = 0;
   out_3198289938668904119[7] = state[5];
   out_3198289938668904119[8] = -state[4];
   out_3198289938668904119[9] = 0;
   out_3198289938668904119[10] = 0;
   out_3198289938668904119[11] = 0;
   out_3198289938668904119[12] = 1;
   out_3198289938668904119[13] = 0;
   out_3198289938668904119[14] = 0;
   out_3198289938668904119[15] = 1;
   out_3198289938668904119[16] = 0;
   out_3198289938668904119[17] = 0;
   out_3198289938668904119[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3198289938668904119[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3198289938668904119[20] = 0;
   out_3198289938668904119[21] = state[8];
   out_3198289938668904119[22] = 0;
   out_3198289938668904119[23] = -state[6];
   out_3198289938668904119[24] = -state[5];
   out_3198289938668904119[25] = 0;
   out_3198289938668904119[26] = state[3];
   out_3198289938668904119[27] = 0;
   out_3198289938668904119[28] = 0;
   out_3198289938668904119[29] = 0;
   out_3198289938668904119[30] = 0;
   out_3198289938668904119[31] = 1;
   out_3198289938668904119[32] = 0;
   out_3198289938668904119[33] = 0;
   out_3198289938668904119[34] = 1;
   out_3198289938668904119[35] = 0;
   out_3198289938668904119[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3198289938668904119[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3198289938668904119[38] = 0;
   out_3198289938668904119[39] = -state[7];
   out_3198289938668904119[40] = state[6];
   out_3198289938668904119[41] = 0;
   out_3198289938668904119[42] = state[4];
   out_3198289938668904119[43] = -state[3];
   out_3198289938668904119[44] = 0;
   out_3198289938668904119[45] = 0;
   out_3198289938668904119[46] = 0;
   out_3198289938668904119[47] = 0;
   out_3198289938668904119[48] = 0;
   out_3198289938668904119[49] = 0;
   out_3198289938668904119[50] = 1;
   out_3198289938668904119[51] = 0;
   out_3198289938668904119[52] = 0;
   out_3198289938668904119[53] = 1;
}
void h_13(double *state, double *unused, double *out_8475459522330600330) {
   out_8475459522330600330[0] = state[3];
   out_8475459522330600330[1] = state[4];
   out_8475459522330600330[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2142215374310065574) {
   out_2142215374310065574[0] = 0;
   out_2142215374310065574[1] = 0;
   out_2142215374310065574[2] = 0;
   out_2142215374310065574[3] = 1;
   out_2142215374310065574[4] = 0;
   out_2142215374310065574[5] = 0;
   out_2142215374310065574[6] = 0;
   out_2142215374310065574[7] = 0;
   out_2142215374310065574[8] = 0;
   out_2142215374310065574[9] = 0;
   out_2142215374310065574[10] = 0;
   out_2142215374310065574[11] = 0;
   out_2142215374310065574[12] = 0;
   out_2142215374310065574[13] = 0;
   out_2142215374310065574[14] = 0;
   out_2142215374310065574[15] = 0;
   out_2142215374310065574[16] = 0;
   out_2142215374310065574[17] = 0;
   out_2142215374310065574[18] = 0;
   out_2142215374310065574[19] = 0;
   out_2142215374310065574[20] = 0;
   out_2142215374310065574[21] = 0;
   out_2142215374310065574[22] = 1;
   out_2142215374310065574[23] = 0;
   out_2142215374310065574[24] = 0;
   out_2142215374310065574[25] = 0;
   out_2142215374310065574[26] = 0;
   out_2142215374310065574[27] = 0;
   out_2142215374310065574[28] = 0;
   out_2142215374310065574[29] = 0;
   out_2142215374310065574[30] = 0;
   out_2142215374310065574[31] = 0;
   out_2142215374310065574[32] = 0;
   out_2142215374310065574[33] = 0;
   out_2142215374310065574[34] = 0;
   out_2142215374310065574[35] = 0;
   out_2142215374310065574[36] = 0;
   out_2142215374310065574[37] = 0;
   out_2142215374310065574[38] = 0;
   out_2142215374310065574[39] = 0;
   out_2142215374310065574[40] = 0;
   out_2142215374310065574[41] = 1;
   out_2142215374310065574[42] = 0;
   out_2142215374310065574[43] = 0;
   out_2142215374310065574[44] = 0;
   out_2142215374310065574[45] = 0;
   out_2142215374310065574[46] = 0;
   out_2142215374310065574[47] = 0;
   out_2142215374310065574[48] = 0;
   out_2142215374310065574[49] = 0;
   out_2142215374310065574[50] = 0;
   out_2142215374310065574[51] = 0;
   out_2142215374310065574[52] = 0;
   out_2142215374310065574[53] = 0;
}
void h_14(double *state, double *unused, double *out_6948548336381976858) {
   out_6948548336381976858[0] = state[6];
   out_6948548336381976858[1] = state[7];
   out_6948548336381976858[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1505174977667150826) {
   out_1505174977667150826[0] = 0;
   out_1505174977667150826[1] = 0;
   out_1505174977667150826[2] = 0;
   out_1505174977667150826[3] = 0;
   out_1505174977667150826[4] = 0;
   out_1505174977667150826[5] = 0;
   out_1505174977667150826[6] = 1;
   out_1505174977667150826[7] = 0;
   out_1505174977667150826[8] = 0;
   out_1505174977667150826[9] = 0;
   out_1505174977667150826[10] = 0;
   out_1505174977667150826[11] = 0;
   out_1505174977667150826[12] = 0;
   out_1505174977667150826[13] = 0;
   out_1505174977667150826[14] = 0;
   out_1505174977667150826[15] = 0;
   out_1505174977667150826[16] = 0;
   out_1505174977667150826[17] = 0;
   out_1505174977667150826[18] = 0;
   out_1505174977667150826[19] = 0;
   out_1505174977667150826[20] = 0;
   out_1505174977667150826[21] = 0;
   out_1505174977667150826[22] = 0;
   out_1505174977667150826[23] = 0;
   out_1505174977667150826[24] = 0;
   out_1505174977667150826[25] = 1;
   out_1505174977667150826[26] = 0;
   out_1505174977667150826[27] = 0;
   out_1505174977667150826[28] = 0;
   out_1505174977667150826[29] = 0;
   out_1505174977667150826[30] = 0;
   out_1505174977667150826[31] = 0;
   out_1505174977667150826[32] = 0;
   out_1505174977667150826[33] = 0;
   out_1505174977667150826[34] = 0;
   out_1505174977667150826[35] = 0;
   out_1505174977667150826[36] = 0;
   out_1505174977667150826[37] = 0;
   out_1505174977667150826[38] = 0;
   out_1505174977667150826[39] = 0;
   out_1505174977667150826[40] = 0;
   out_1505174977667150826[41] = 0;
   out_1505174977667150826[42] = 0;
   out_1505174977667150826[43] = 0;
   out_1505174977667150826[44] = 1;
   out_1505174977667150826[45] = 0;
   out_1505174977667150826[46] = 0;
   out_1505174977667150826[47] = 0;
   out_1505174977667150826[48] = 0;
   out_1505174977667150826[49] = 0;
   out_1505174977667150826[50] = 0;
   out_1505174977667150826[51] = 0;
   out_1505174977667150826[52] = 0;
   out_1505174977667150826[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_1566483945621839879) {
  err_fun(nom_x, delta_x, out_1566483945621839879);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5680128566882367357) {
  inv_err_fun(nom_x, true_x, out_5680128566882367357);
}
void pose_H_mod_fun(double *state, double *out_9206521029859008689) {
  H_mod_fun(state, out_9206521029859008689);
}
void pose_f_fun(double *state, double dt, double *out_6263565860580378794) {
  f_fun(state,  dt, out_6263565860580378794);
}
void pose_F_fun(double *state, double dt, double *out_5475119388677115833) {
  F_fun(state,  dt, out_5475119388677115833);
}
void pose_h_4(double *state, double *unused, double *out_2784573447061806248) {
  h_4(state, unused, out_2784573447061806248);
}
void pose_H_4(double *state, double *unused, double *out_5468415834006635355) {
  H_4(state, unused, out_5468415834006635355);
}
void pose_h_10(double *state, double *unused, double *out_2001396750132265268) {
  h_10(state, unused, out_2001396750132265268);
}
void pose_H_10(double *state, double *unused, double *out_3198289938668904119) {
  H_10(state, unused, out_3198289938668904119);
}
void pose_h_13(double *state, double *unused, double *out_8475459522330600330) {
  h_13(state, unused, out_8475459522330600330);
}
void pose_H_13(double *state, double *unused, double *out_2142215374310065574) {
  H_13(state, unused, out_2142215374310065574);
}
void pose_h_14(double *state, double *unused, double *out_6948548336381976858) {
  h_14(state, unused, out_6948548336381976858);
}
void pose_H_14(double *state, double *unused, double *out_1505174977667150826) {
  H_14(state, unused, out_1505174977667150826);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
