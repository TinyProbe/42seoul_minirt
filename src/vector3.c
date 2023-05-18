#include "minirt.h"

t_vec	cross(t_vec *v, t_vec *v2)
{
	return (make_vec(\
		v->y * v2->z - v->z * v2->y,\
		v->z * v2->x - v->x * v2->z,\
		v->x * v2->y - v->y * v2->x));
}

t_f32	dot(t_vec *v, t_vec *v2)
{
	return (v->x * v2->x\
		+ v->y * v2->y\
		+ v->z * v2->z);
}

t_f32	length_squared(t_vec *v)
{
	return (v->x * v->x\
		+ v->y * v->y\
		+ v->z * v->z);
}

t_f32	length(t_vec *v)
{
	return (sqrt(length_squared(v)));
}

t_vec	unt_vec(t_vec *v)
{
	return (div_vec_(v, length(v)));
}
