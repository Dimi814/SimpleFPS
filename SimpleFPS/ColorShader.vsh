
attribute vec3 aPositionVertex;

void main()
{
    gl_Position = gl_ModelViewProjectionMatrix * vec4(aPositionVertex, 1.0);
}