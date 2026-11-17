#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_1566483945621839879);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5680128566882367357);
void pose_H_mod_fun(double *state, double *out_9206521029859008689);
void pose_f_fun(double *state, double dt, double *out_6263565860580378794);
void pose_F_fun(double *state, double dt, double *out_5475119388677115833);
void pose_h_4(double *state, double *unused, double *out_2784573447061806248);
void pose_H_4(double *state, double *unused, double *out_5468415834006635355);
void pose_h_10(double *state, double *unused, double *out_2001396750132265268);
void pose_H_10(double *state, double *unused, double *out_3198289938668904119);
void pose_h_13(double *state, double *unused, double *out_8475459522330600330);
void pose_H_13(double *state, double *unused, double *out_2142215374310065574);
void pose_h_14(double *state, double *unused, double *out_6948548336381976858);
void pose_H_14(double *state, double *unused, double *out_1505174977667150826);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}