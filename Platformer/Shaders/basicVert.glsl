#version 330 core

in vec4 position;

uniform Mat4 projection;

void main 
{
	gl_Position = projection * position; 
}