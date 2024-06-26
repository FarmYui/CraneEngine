// Basic Color Texture Shader

#type vertex
#version 450

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TextureCoordinates;
layout(location = 3) in float a_TextureIndex;
layout(location = 4) in int a_EntityID;

out vec4 v_Color;
out vec2 v_TextureCoordinates;
out flat float v_TextureIndex;
out flat int v_EntityID;

uniform mat4 u_ViewProjection;

void main()
{
	v_Color = a_Color;
	v_TextureCoordinates = a_TextureCoordinates;
	v_TextureIndex = a_TextureIndex;
	v_EntityID = a_EntityID;

	gl_Position = u_ViewProjection * vec4(a_Position ,1.0f);
}



#type fragment
#version 450
			
layout(location = 0) out vec4 color;
layout(location = 1) out int entityID;

in vec4 v_Color;
in vec2 v_TextureCoordinates;
in flat float v_TextureIndex;
in flat int v_EntityID;

uniform sampler2D u_Textures[32];

void main()
{
	int index = int(v_TextureIndex);
	color = texture(u_Textures[index], v_TextureCoordinates) * v_Color;

	entityID = v_EntityID;
}