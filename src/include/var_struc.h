#ifndef VARSTRUC_H
#define VARSTRUC_H


#define EPS 0.0000000001


#define N_CONF 400

extern double config[];

#define CONF_INI(i,j) printf("%3d-th configuration = %g .\n", i, j)

#define CONF_ERR(n)														\
	do {																\
		fprintf(stderr, "Error in the %d-th value of the configuration!\n", n); \
		exit(2);														\
	} while (0)


//fluid
struct flu_var {
	double *RHO, *U, *V, *W, *P, *PHI, *gamma;
};

//cell
struct cell_var {
	int **cell_cell;
	double **n_x, **n_y, **n_z;
	double **F_rho, **F_e, **F_gamma, **F_phi, **F_u, **F_v, **F_w;
	double  *U_rho,  *U_e,  *U_gamma,  *U_phi,  *U_u,  *U_v,  *U_w;
	double *U0_rho, *U0_e, *U0_gamma, *U0_phi, *U0_u, *U0_v, *U0_w;
	double    *U_p,    *V_p,    *F_pc_x,    *F_pc_y;
	double *dt_U_p, *dt_V_p, *dt_F_pc_x, *dt_F_pc_y;
	double *X_c, *Y_c, *Z_c;
	double *vol, *c, *dist_p;
	double *gradx_rho,   *grady_rho,   *gradz_rho;
	double *gradx_phi,   *grady_phi,   *gradz_phi;
	double *gradx_gamma, *grady_gamma, *gradz_gamma;
	double *gradx_e,     *grady_e,     *gradz_e;
	double *gradx_u,     *grady_u,     *gradz_u;
	double *gradx_v,     *grady_v,     *gradz_v;
	double *gradx_w,     *grady_w,     *gradz_w;
};

//interface
struct i_f_var {
	double n_x, n_y, n_z;
	double delta_x, delta_y, delta_z;
	double F_rho, F_e, F_gamma, F_phi, F_u, F_v, F_w;
	double U_rho, U_e, U_gamma, U_phi, U_u, U_v, U_w;
	double   RHO,   P,   gamma,   PHI,   U,   V,   W;
	double       dt_p,                dt_u;
	double length;
	double d_rho;
	double d_phi;
	double d_gamma;
	double d_e;
	double d_p;
	double d_u;
	double d_v;
	double d_w;
};

//mesh
struct mesh_var {
	int num_pt, num_ghost, *cell_type, **cell_pt;
	int num_border[10], *border_pt, *border_cond, *peri_cell;
	double *X, *Y, *Z;
	void (*bc)(struct cell_var * cv, struct mesh_var mv, struct flu_var * FV, double t);
};
	
#endif
