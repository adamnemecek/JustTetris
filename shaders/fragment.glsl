// 
// Filename: fragment.glsl
// Created: 2018-01-31 16:51:56 +0100
// Author: Felix Naredi
// 

#version 130

out vec4 FragColor;

in vec4 vertexColor;

void main()
{
    FragColor = vertexColor;
}
 
