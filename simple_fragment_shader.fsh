uniform sampler2D u_texture;
varying highp vec4 v_texcoord;

varying mediump vec4 v_color;

void main(void)
{
    gl_FragColor = texture2D(u_texture, v_texcoord.st);
    //gl_FragColor = v_color;
}

