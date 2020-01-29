#version 150

// these are for the programmable pipeline system
uniform mat4 modelViewProjectionMatrix;
// in OF the position attribute is a vec4
in vec4 position;
// this is the normal from the mesh
in vec3 normal;
out vec3 myNormal;
// the time value is passed into the shader by the OF app.
uniform float time;
uniform vec2 mouse;

float rand(vec3 x) {
    // FM noise
    return abs(sin(cos(dot(x,vec3(mouse.x,mouse.y,mouse.x)))* 100.));
}

void main()
{
    float angle = time;
    //rotation
    mat4 rotateX = mat4(1,0,0,0,0,cos(angle),sin(angle),0,0,-sin(angle),cos(angle),0,0,0,0,1);
    
    myNormal = normal;

    vec3 newPosition = position.xyz * (1.0 +(0.2 * (rand(position.xyz))));
    
// we need to make the new positions into a vec4 so we can apply the rotation matrix
    vec4 rotatedPos = rotateX * vec4(newPosition,1.0);
// we're now ready to generate the new normals after the rotation.
// this is crucial otherwise it will look like our light is also rotating
    myNormal = normalize(rotatedPos.xyz);
    
    gl_Position = modelViewProjectionMatrix * vec4(rotatedPos.xyz,1.);
}
