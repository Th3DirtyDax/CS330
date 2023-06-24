/*
* GSLS Language Integration for VS2022 installed
*/


//Used to create an easy file location to make shader changes

#version 330 core
	
out vec4 FragColor;
in vec4 vertexColor;
in vec2 texCoord;

uniform sampler2D tex0;


void main() {

	FragColor = texture(tex0, texCoord);
	
}