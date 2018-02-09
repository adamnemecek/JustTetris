//  
//  Filename: vertex.glsl
//  Created: 2018-01-31 16:49:27 +0100
//  Author: Felix Naredi
//

#version 130

in vec3 position;
in vec3 color;

out vec4 vertexColor;

void main()
{
    gl_Position = vec4(position, 1.0f);
    vertexColor = vec4(color, 1.0f);
}
 
