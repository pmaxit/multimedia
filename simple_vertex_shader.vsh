attribute highp vec4 a_texcoord;
varying highp vec4 v_texcoord;

attribute highp vec4 a_vertex;
attribute mediump vec4 a_color;
uniform highp mat4 u_mvpMatrix;
uniform lowp vec4 u_color;

varying mediump vec4 v_color;

void main(void)
{
    gl_Position = u_mvpMatrix * a_vertex;
    v_color = a_color;
    v_texcoord = a_texcoord;
}
