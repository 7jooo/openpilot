#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_6934108206099716844);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5572543593475452920);
void car_H_mod_fun(double *state, double *out_1769066394591392073);
void car_f_fun(double *state, double dt, double *out_4651087275089365457);
void car_F_fun(double *state, double dt, double *out_4368563689476655574);
void car_h_25(double *state, double *unused, double *out_1403048431662854044);
void car_H_25(double *state, double *unused, double *out_7484489453205922306);
void car_h_24(double *state, double *unused, double *out_2485532053118535027);
void car_H_24(double *state, double *unused, double *out_1734189434434434085);
void car_h_30(double *state, double *unused, double *out_2234401096591168306);
void car_H_30(double *state, double *unused, double *out_2956793123078314108);
void car_h_26(double *state, double *unused, double *out_5271187148035500991);
void car_H_26(double *state, double *unused, double *out_3742986134331866082);
void car_h_27(double *state, double *unused, double *out_7393261032603143096);
void car_H_27(double *state, double *unused, double *out_782029811277889197);
void car_h_29(double *state, double *unused, double *out_7236074364252013951);
void car_H_29(double *state, double *unused, double *out_3467024467392706292);
void car_h_28(double *state, double *unused, double *out_5987065522388065797);
void car_H_28(double *state, double *unused, double *out_5430654738958032543);
void car_h_31(double *state, double *unused, double *out_8594597544518365840);
void car_H_31(double *state, double *unused, double *out_3116778032098514606);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}