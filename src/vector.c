#include "minirt.h"

// t_vec	make_vec_randomly(float mn, float mx)
// {
// 	t_vec	v;

// 	v.x = random(mn, mx);
// 	v.y = random(mn, mx);
// 	v.z = random(mn, mx);
// 	return (v);
// }

t_vec	extract_vec(t_a *a, t_i8 *val)
{
	t_i8	**xyz;
	t_vec	v;

	xyz = ft_split(val, ',');
	if (count_string(xyz) != 3)
		error(a->msg, ERROR_FILEFORMAT);
	v = make_vec(ft_stof(xyz[0]), ft_stof(xyz[1]), ft_stof(xyz[2]));
	ft_delete_split(xyz);
	return (v);
}

t_vec	make_vec(t_f32 x, t_f32 y, t_f32 z)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec	neg_vec(t_vec *v)
{
	t_vec	v2;

	v2.x = -(v->x);
	v2.y = -(v->y);
	v2.z = -(v->z);
	return (v2);
}

t_vec	sum_vec(t_vec *v, t_vec *v2)
{
	t_vec	v3;

	v3.x = v->x + v2->x;
	v3.y = v->y + v2->y;
	v3.z = v->z + v2->z;
	return (v3);
}

t_vec	sub_vec(t_vec *v, t_vec *v2)
{
	t_vec	v3;

	v3.x = v->x - v2->x;
	v3.y = v->y - v2->y;
	v3.z = v->z - v2->z;
	return (v3);
}
