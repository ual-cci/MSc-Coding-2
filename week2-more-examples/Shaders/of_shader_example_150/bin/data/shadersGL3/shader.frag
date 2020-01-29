#version 150

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;
in vec3 myNormal;

out vec4 outputColor;
 
void main()
{
    // light from the top
    vec3 light = vec3(0.,10.,5.);
    
    // Get the normal of the light
    // Remember the Unit Vector of the light is the direction of the light
    
    light = normalize(light);
    
    // return the maximum of either 0, or the squared distance
    // This means you can add an ambient light later without
    // getting weird values from the output of the dot prod.
    float prod = max(0., dot(myNormal,light));
    // use the dot product of the normal and the light
    // To calculate the shading for the sphere
    outputColor = vec4(prod, prod, prod, 1.0) + vec4(0.2,0.2,0.2,1.0);
}
