attribute vec3 aPositionVertex;
attribute vec3 aPositionNormal;

varying vec4 vFinalVertexColor;

void main()
{
    vec3 normal = normalize(gl_NormalMatrix * aPositionNormal);
    
    vec3 lightPosition = normalize(vec3( -1.0, 1.0, 2.0));
    
    float dotProduct = max(dot(normal, lightPosition), 0.0);
    
    vFinalVertexColor = dotProduct * vec4(1.0, 0.0, 0.0, 1.0);
    
    gl_Position = gl_ModelViewProjectionMatrix * vec4(aPositionVertex, 1.0);
}