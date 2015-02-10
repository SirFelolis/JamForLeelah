#version 330 

uniform mat4 mv_mat; 
uniform mat3 norm_mat; 
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv; 
layout(location = 2) in vec3 normal; 
out vec2 var_uv; 
out vec3 var_normal; 

void main() { 
	gl_Position = mv_mat * vec4(position, 1.0);
	var_uv = uv;
	var_uv.y *= -1.0;
	var_normal = normal;
}