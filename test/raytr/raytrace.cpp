#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <float.h>
using namespace std;

//
// random value generator.
// void		IinitWELLRNG512a(unsigned int *)
// double	WELLRNG512a(void)
// void		initRandom(void)
// double	random(double, double)
//
#define W	32
#define R	16
#define P	0
#define M1	13
#define M2	9
#define M3	5

#define MAT0POS(t,v)	(v^(v>>t))
#define MAT0NEG(t,v)	(v^(v<<(-(t))))
#define MAT3NEG(t,v)	(v<<(-(t)))
#define MAT4NEG(t,b,v)	(v^((v<<(-(t)))&b))

#define V0		STATE[state_i]
#define VM1		STATE[(state_i+M1) & 0x0000000fU]
#define VM2		STATE[(state_i+M2) & 0x0000000fU]
#define VM3		STATE[(state_i+M3) & 0x0000000fU]
#define VRm1	STATE[(state_i+15) & 0x0000000fU]
#define VRm2	STATE[(state_i+14) & 0x0000000fU]
#define newV0	STATE[(state_i+15) & 0x0000000fU]
#define newV1	STATE[state_i]
#define newVRm1	STATE[(state_i+14) & 0x0000000fU]

#define FACT	2.32830643653869628906e-10

static unsigned int	state_i, z0, z1, z2, STATE[R];
void	InitWELLRNG512a(unsigned int *init)
{
	state_i = 0;
	memcpy(STATE, init, sizeof(unsigned int) * R);
}
double	WELLRNG512a(void)
{
	z0 = VRm1;
	z1 = MAT0NEG(-16, V0) ^ MAT0NEG(-15, VM1);
	z2 = MAT0POS(11, VM2);
	newV1 = z1 ^ z2; 
	newV0 = MAT0NEG(-2, z0) ^ MAT0NEG(-18, z1) ^\
		MAT3NEG(-28, z2) ^ MAT4NEG(-5,0xda442d24U, newV1);
	state_i = (state_i + 15) & 0x0000000fU;
	return (((double) STATE[state_i]) * FACT);
}
void	initRandom(void)
{
	unsigned int	init[R];
	int				i;

	i = -1;
	while (++i < R)
		init[i] = (i + 3)\
			* 11 % (1 << 11) * 22 % (1 << 13) * 33 % (1 << 15)\
			* 44 % (1 << 14) * 55 % (1 << 16) * 66 % (1 << 18)\
			* 77 % (1 << 17) * 88 % (1 << 19) * 99 % (1 << 21);
	InitWELLRNG512a(init);
}
double	random(double mn, double mx)
{
	return ((WELLRNG512a() * (mx - mn)) + mn);
}

#define INF FLT_MAX
#define PI 3.1416f
float	dtorad(float degree)
{
	return (degree * PI / 180.f);
}

//
// struct	t_vec
// t_vec	make_vec(float, float, float)
// t_vec	make_vec_randomly(float, float)
// t_vec	neg_vec(t_vec)
// t_vec	sum_vec(t_vec, t_vec)
// t_vec	sub_vec(t_vec, t_vec)
// t_vec	mlt_vec(t_vec, t_vec)
// t_vec	div_vec(t_vec, t_vec)
// t_vec	mlt_vec2(t_vec, float)
// t_vec	div_vec2(t_vec, float)
// t_vec	cross(t_vec, t_vec)
// float	dot(t_vec, t_vec)
// float	length_squared(t_vec)
// float	length(t_vec)
// t_vec	unt_vec(t_vec)
// bool		near_zero(t_vec)
//
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
t_vec	make_vec_randomly(float mn, float mx)
{
	t_vec	vec;

	vec.x = random(mn, mx);
	vec.y = random(mn, mx);
	vec.z = random(mn, mx);
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
bool	near_zero(t_vec vec)
{
	static const float	s = 1e-8;

	return (fabs(vec.x) < s && fabs(vec.y) < s && fabs(vec.z) < s);
}

//
// struct	t_ray
// t_ray	make_ray(t_vec, t_vec)
// t_vec	at_point(const t_ray *, float)
//
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
t_vec	at_point(const t_ray *ray, float t)
{
	return (sum_vec(ray->org, mlt_vec2(ray->dir, t)));
}

//
// struct	t_record
// void		face_normal(t_record, const t_ray *, t_vec)
//
typedef struct s_record
{
	t_vec	pos;
	t_vec	normal;
	float	t;
	bool	front_face;
	void	*scatter;
	t_vec	albedo;
	float	fuzz;
}	t_record;
void set_face_normal(t_record *rec, const t_ray *ray, t_vec outward_normal)
{
	rec->front_face = dot(ray->dir, outward_normal) < 0;
	if (rec->front_face)
		rec->normal = outward_normal;
	else
		rec->normal = neg_vec(outward_normal);
}

//
// struct	t_sphere
// t_sphere	make_sphere(t_vec, float, t_mat, t_vec)
// t_vec	random_vec_in_unit_sphere()
// t_vec	random_unit_vec()
// t_vec	random_in_hemisphere(t_vec)
// bool		hit(const t_sphere *, const t_ray *, float, float, t_record *)
//
typedef struct s_sphere
{
	t_vec	ctr;
	float	radius;
	void	*scatter;
	t_vec	albedo;
	float	fuzz;
}	t_sphere;
t_sphere	make_sphere(t_vec ctr, float radius, void *scatter, t_vec albedo, float fuzz)
{
	t_sphere	sph;

	sph.ctr = ctr;
	sph.radius = radius;
	sph.scatter = scatter;
	sph.albedo = albedo;
	sph.fuzz = fuzz;
	return (sph);
}
t_vec	random_vec_in_unit_sphere()
{
	t_vec	p;

	while (true)
	{
		p = make_vec_randomly(-1, 1);
		if (length_squared(p) < 1)
			return (p);
	}
}
t_vec	random_unit_vec()
{
	return (unt_vec(random_vec_in_unit_sphere()));
}
t_vec	random_in_hemisphere(t_vec normal)
{
	t_vec	in_unit_sphere = random_vec_in_unit_sphere();
	if (dot(in_unit_sphere, normal) > 0.f)
		return (in_unit_sphere);
	else
		return (neg_vec(in_unit_sphere));
}
bool	hit(const t_sphere *sph, const t_ray *ray, float t_mn, float t_mx, t_record *rec)
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
		return (false);
	sqrtd = sqrt(discriminant);
	root = (-h - sqrtd) / a;
	if (root < t_mn || t_mx < root) {
		root = (-h + sqrtd) / a;
		if (root < t_mn || t_mx < root)
			return (false);
	}
	rec->t = root;
	rec->pos = at_point(ray, rec->t);
	rec->scatter = sph->scatter;
	rec->albedo = sph->albedo;
	rec->fuzz = sph->fuzz;
	outward_normal = div_vec2(sub_vec(rec->pos, sph->ctr), sph->radius);
	set_face_normal(rec, ray, outward_normal);
	return (true);
}

//
// struct	t_lst
// bool		hit(const t_list *, const t_ray *, float, float, t_record *)
//
typedef struct s_lst
{
	std::vector<t_sphere>	_;
}	t_lst;
bool	hit(const t_lst *lst, const t_ray *ray, float t_mn, float t_mx, t_record *rec)
{
	t_record	tmp;
	bool		is_hit;
	float		closest;
	int			i;

	is_hit = false;
	closest = t_mx;
	i = -1;
	while (++i < (int) lst->_.size())
	{
		if (hit(&(lst->_[i]), ray, t_mn, closest, &tmp))
		{
			is_hit = true;
			closest = tmp.t;
			*rec = tmp;
		}
	}
	return (is_hit);
}

//
// struct	t_camera
// void		initCam(t_camera *, float, float)
// t_ray	getRay(t_camera *, float, float)
//
typedef struct s_camera
{
	t_vec	org;
	t_vec	lowleft;
	t_vec	hor;
	t_vec	ver;
}	t_camera;
void	initCam(
	t_camera *cam,
	t_vec lookfrom,
	t_vec lookat,
	t_vec vup,
	float vfov,
	float aspect_ratio)
{
	float	theta;
	float	h;
	float	viewport_height;
	float	viewport_width;
	t_vec	w;
	t_vec	u;
	t_vec	v;

	theta = dtorad(180.0 - vfov);
	h = tan(theta / 2);
	viewport_height = 2.0 / h;
	viewport_width = aspect_ratio * viewport_height;
	w = unt_vec(sub_vec(lookfrom, lookat));
	u = unt_vec(cross(vup, w));
	v = cross(w, u);
	cam->org = lookfrom;
	cam->hor = mlt_vec2(u, viewport_width);
	cam->ver = mlt_vec2(v, viewport_height);
	cam->lowleft = sub_vec(sub_vec(sub_vec(cam->org,\
		div_vec2(cam->hor, 2)), div_vec2(cam->ver, 2)), w);
}
t_ray	getRay(t_camera *cam, float s, float t)
{
	return (make_ray(cam->org, sub_vec(sum_vec(sum_vec(cam->lowleft,\
		mlt_vec2(cam->hor, s)), mlt_vec2(cam->ver, t)), cam->org)));
}

//
// scatters
//
bool	scatter_lamb(
	const t_ray		*ray_in,
	const t_record	*rec,
	t_vec			*attenuation,
	t_ray			*scattered)
{
	t_vec	scatter_dir;

	(void) ray_in;
	scatter_dir = sum_vec(rec->normal, random_unit_vec());
	if (near_zero(scatter_dir))
		scatter_dir = rec->normal;
	*scattered = make_ray(rec->pos, scatter_dir);
	*attenuation = rec->albedo;
	return (true);
}
t_vec	reflect(t_vec v, t_vec n)
{
	return (sub_vec(v, mlt_vec2(n, 2 * dot(v, n))));
}
bool	scatter_metal(
	const t_ray		*ray_in,
	const t_record	*rec,
	t_vec			*attenuation,
	t_ray			*scattered)
{
	t_vec	reflected;

	reflected = reflect(unt_vec(ray_in->dir), rec->normal);
	*scattered = make_ray(rec->pos, sum_vec(reflected,\
		mlt_vec2(random_vec_in_unit_sphere(), rec->fuzz)));
	*attenuation = rec->albedo;
	return (dot(scattered->dir, rec->normal) > 0);
}

//
// utilitys
// t_vec	ray_color(const t_ray *, t_list *, int)
// float	clamp(float, float, float)
// int		icolor(t_vec)
// void		write_color(t_vec, int)
//
t_vec	ray_color(const t_ray *ray, t_lst *lst, int depth)
{
	t_record	rec;
	t_vec		unt_dir;
	float		t;
	t_vec		attenuation;
	t_ray		scattered;

	if (depth < 1)
		return (make_vec(0, 0, 0));
	if (hit(lst, ray, 0.002f, INF, &rec))
	{
		if (((bool (*)(const t_ray *, const struct s_record *, t_vec *,\
			t_ray *)) rec.scatter)(ray, &rec, &attenuation, &scattered))
			return (mlt_vec(attenuation, ray_color(&scattered, lst, depth - 1)));
		return (make_vec(0, 0, 0));
	}
	unt_dir = unt_vec(ray->dir);
	t = 0.5f * (unt_dir.y + 1.f);
	return (sum_vec(mlt_vec2(make_vec(1.f, 1.f, 1.f), 1.f - t),\
		mlt_vec2(make_vec(0.5f, 0.7f, 1.f), t)));
}
float	clamp(float x, float mn, float mx)
{
	if (x < mn)
		return (mn);
	if (x > mx)
		return (mx);
	return (x);
}
int	icolor(t_vec unit_color)
{
	int	rtn;

	rtn = 0;
	((unsigned char *) &rtn)[2] = 256 * clamp(unit_color.x, 0.f, 0.999f);
	((unsigned char *) &rtn)[1] = 256 * clamp(unit_color.y, 0.f, 0.999f);
	((unsigned char *) &rtn)[0] = 256 * clamp(unit_color.z, 0.f, 0.999f);
	return (rtn);
}
void	write_color(t_vec clr, int samplepp)
{
	float			scale;
	int				iclr;
	unsigned char	*color;

	scale = 1.f / samplepp;
	clr.x = sqrt(clr.x * scale);
	clr.y = sqrt(clr.y * scale);
	clr.z = sqrt(clr.z * scale);
	iclr = icolor(clr);
	color = (unsigned char *) &iclr;
	printf("%d %d %d\n", color[2], color[1], color[0]);
}

int	main(void)
{
	// WELLRNG512a init
	initRandom();

	// screen
	const float aspect_ratio = 16.f / 9.f;
	const int image_width = 720;
	const int image_height = image_width / aspect_ratio;
	const int samplepp = 100;
	const int max_depth = 50;

	// world
	t_lst lst;
	lst._.push_back(make_sphere(make_vec( 0.0, -1000.5, -1.0), 1000.0, (void *) scatter_lamb,  make_vec(0.8, 0.8, 0.0), 0.0));
	lst._.push_back(make_sphere(make_vec( 0.0,     0.0, -1.0),    0.5, (void *) scatter_lamb,  make_vec(0.1, 0.2, 0.5), 0.0));
	lst._.push_back(make_sphere(make_vec(-1.0,     0.0, -1.0),    0.5, (void *) scatter_metal, make_vec(0.8, 0.8, 0.8), 0.0));
	lst._.push_back(make_sphere(make_vec( 1.0,     0.0, -1.0),    0.5, (void *) scatter_metal, make_vec(0.8, 0.6, 0.4), 0.0));

	// camera
	t_camera cam;
	initCam(&cam, make_vec(-1, 0.4, 0.4), make_vec(0, -0.2, -1.8), make_vec(0, 1, 0), 90.0, aspect_ratio);

	std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
	for (int j = image_height - 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i)
		{
			t_vec pixel_color = make_vec(0, 0, 0);
			for (int k = 0; k < samplepp; ++k)
			{
				float u = (i + random(0.0, 1.0)) / (image_width - 1);
				float v = (j + random(0.0, 1.0)) / (image_height - 1);
				t_ray ray = getRay(&cam, u, v);
				pixel_color = sum_vec(pixel_color, ray_color(&ray, &lst, max_depth));
			}
			write_color(pixel_color, samplepp);
		}
	}
}
