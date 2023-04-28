#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;
t_vec	make_vec(float x, float y, float z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
t_vec	neg_vec(t_vec vec)
{
	vec.x = -vec.x;
	vec.y = -vec.y;
	vec.z = -vec.z;
	return (vec);
}
t_vec	sum_vec(t_vec vec, t_vec vec2)
{
	vec.x += vec2.x;
	vec.y += vec2.y;
	vec.z += vec2.z;
	return (vec);
}
t_vec	sub_vec(t_vec vec, t_vec vec2)
{
	vec.x -= vec2.x;
	vec.y -= vec2.y;
	vec.z -= vec2.z;
	return (vec);
}
t_vec	mlt_vec(t_vec vec, t_vec vec2)
{
	vec.x *= vec2.x;
	vec.y *= vec2.y;
	vec.z *= vec2.z;
	return (vec);
}
t_vec	div_vec(t_vec vec, t_vec vec2)
{
	vec.x /= vec2.x;
	vec.y /= vec2.y;
	vec.z /= vec2.z;
	return (vec);
}
t_vec	mlt_vec2(t_vec vec, float t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}
t_vec	div_vec2(t_vec vec, float t)
{
	vec.x /= t;
	vec.y /= t;
	vec.z /= t;
	return (vec);
}
t_vec	cross(t_vec vec, t_vec vec2)
{
	return (make_vec(\
		vec.y * vec2.z - vec.z * vec2.y,\
		vec.z * vec2.x - vec.x * vec2.z,\
		vec.x * vec2.y - vec.y * vec2.x));
}
float	dot(t_vec vec, t_vec vec2)
{
	return (vec.x * vec2.x +\
		vec.y * vec2.y +\
		vec.z * vec2.z);
}
float	length_squared(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
float	length(t_vec vec)
{
	return (sqrt(length_squared(vec)));
}
t_vec	unt_vec(t_vec vec)
{
	return (div_vec2(vec, length(vec)));
}
int	icolor(t_vec unit_color)
{
	int	rtn;

	rtn = 0;
	((unsigned char *) &rtn)[2] = (int) (255.999 * unit_color.x);
	((unsigned char *) &rtn)[1] = (int) (255.999 * unit_color.y);
	((unsigned char *) &rtn)[0] = (int) (255.999 * unit_color.z);
	return (rtn);
}

typedef struct s_ray
{
	t_vec	org;
	t_vec	dir;
}	t_ray;
t_ray	make_ray(t_vec org, t_vec dir)
{
	t_ray	ray;

	ray.org = org;
	ray.dir = dir;
	return (ray);
}
t_vec	at_point(t_ray ray, float t)
{
	return (sum_vec(ray.org, mlt_vec2(ray.dir, t)));
}
t_vec	base_color(t_ray ray)
{
	t_vec	unt_dir;
	float	t;

	unt_dir = unt_vec(ray.dir);
	t = 0.5f * (unt_dir.y + 1.f);
	return (sum_vec(mlt_vec2(make_vec(1.f, 1.f, 1.f), 1.f - t),\
		mlt_vec2(make_vec(0.5f, 0.7f, 1.f), t)));
}
float	hit_sphere(const t_vec ctr, float radius, t_ray ray)
{
	t_vec	oc;
	float	a;
	float	h;
	float	c;
	float	discriminant;

	oc = sub_vec(ray.org, ctr);
	a = dot(ray.dir, ray.dir);
	h = dot(oc, ray.dir);
	c = dot(oc, oc) - radius * radius;
	discriminant = h * h - a * c;
	if (discriminant < 0)
		return (-1.f);
	else
		return ((-h - sqrt(discriminant)) / a);
}

typedef struct s_record
{
	t_vec	pos;
	t_vec	normal;
	float	t;
	bool	front_face;
}	t_record;
void face_normal(t_record *rec, t_ray *ray, t_vec *outward_normal)
{
	rec->front_face = dot(ray->dir, *outward_normal) < 0;
	rec->normal = rec->front_face ? *outward_normal : neg_vec(*outward_normal);
}

typedef struct s_sphere
{
	t_vec	ctr;
	float	radius;
}	t_sphere;
bool	hit(t_sphere *sph, t_ray *ray, float t_mn, float t_mx, t_record *rec)
{
	t_vec	oc;
	float	a;
	float	h;
	float	c;
	float	discriminant;
	float	sqrtd;
	float	root;
	t_vec	outward_normal;

	oc = sub_vec(ray->org, sph->ctr);
	a = length_squared(ray->dir);
	h = dot(oc, ray->dir);
	c = length_squared(oc) - sph->radius * sph->radius;
	discriminant = h * h - a * c;
	if (discriminant < 0)
		return false;
	sqrtd = sqrt(discriminant);
	root = (-h - sqrtd) / a;
	if (root < t_mn || t_mx < root) {
		root = (-h + sqrtd) / a;
		if (root < t_mn || t_mx < root)
			return false;
	}
	rec->t = root;
	rec->pos = at_point(*ray, rec->t);
	outward_normal = div_vec2(sub_vec(rec->pos, sph->ctr), sph->radius);
	face_normal(rec, ray, &outward_normal);
	return true;
}

void	write_color(t_vec clr)
{
	int				iclr;
	unsigned char	*color;

	iclr = icolor(clr);
	color = (unsigned char *) &iclr;
	printf("%d %d %d\n", color[2], color[1], color[0]);
}

int	main(void)
{
	const float aspect_ratio = 16.f / 9.f;
	const int image_width = 400;
	const int image_height = image_width / aspect_ratio;

	float viewport_height = 2.f;
	float viewport_width = aspect_ratio * viewport_height;
	float focal_length = 1.f;

	t_vec origin = make_vec(0, 0, 0);
	t_vec horizontal = make_vec(viewport_width, 0, 0);
	t_vec vertical = make_vec(0, viewport_height, 0);
	t_vec lower_left_corner = sub_vec(sub_vec(sub_vec(\
		origin, div_vec2(horizontal, 2)), div_vec2(vertical, 2)),\
		make_vec(0, 0, focal_length));

	std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
	for (int j = image_height - 1; j >= 0; --j)
	{
// 		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i)
		{
			float u = (float) i / (image_width - 1);
			float v = (float) j / (image_height - 1);
			t_ray ray = make_ray(origin,\
				sub_vec(sum_vec(sum_vec(lower_left_corner,\
				mlt_vec2(horizontal, u)), mlt_vec2(vertical, v)), origin));
			t_vec clr = base_color(ray);
			float t = hit_sphere(make_vec(0, 0, -1), 0.5, ray);
			if (t > 0.f)
			{
				t_vec N = unt_vec(sub_vec(at_point(ray, t), make_vec(0, 0, -1)));
				clr = mlt_vec2(make_vec(N.x + 1, N.y + 1, N.z + 1), 0.5);
			}
			write_color(clr);
		}
	}
}
