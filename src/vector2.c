#include "minirt.h"

t_vec	mlt_vec(t_vec *v, t_vec *v2)
{
	t_vec	v3;

	v3.x = v->x * v2->x;
	v3.y = v->y * v2->y;
	v3.z = v->z * v2->z;
	return (v3);
}

t_vec	div_vec(t_vec *v, t_vec *v2)
{
	t_vec	v3;

	v3.x = v->x / v2->x;
	v3.x = v->y / v2->y;
	v3.x = v->z / v2->z;
	return (v3);
}

t_vec	_mlt_vec(t_f32 t, t_vec *v)
{
	t_vec	v2;

	v2.x = v->x * t;
	v2.y = v->y * t;
	v2.z = v->z * t;
	return (v2);
}

t_vec	mlt_vec_(t_vec *v, t_f32 t)
{
	return (_mlt_vec(t, v));
}

t_vec	div_vec_(t_vec *v, t_f32 t)
{
	t_vec	v2;

	v2.x = v->x / t;
	v2.y = v->y / t;
	v2.z = v->z / t;
	return (v2);
}
