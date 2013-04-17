package com.samsung.myapp;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.opengl.GLSurfaceView.Renderer;
import android.os.Bundle;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("OpenGlSurface");
        System.loadLibrary("MyThread");
    }

    static MyThread t = new MyThread();

    @Override
    protected void onPause() {
        // TODO Auto-generated method stub
        super.onPause();
        t.onPause();
    }

    @Override
    protected void onResume() {
        // TODO Auto-generated method stub
        super.onResume();
        t.onResume();
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        GLSurfaceView v = new GLSurfaceView(getApplication());

        v.setRenderer(new Renderer() {

            @Override
            public void onSurfaceCreated(GL10 gl, EGLConfig config) {
                __OpenGlSurface__.onSurfaceCreated();
            }

            @Override
            public void onSurfaceChanged(GL10 gl, int width, int height) {
                __OpenGlSurface__.onSurfaceChanged(width, height);
            }

            @Override
            public void onDrawFrame(GL10 gl) {
                __OpenGlSurface__.onDrawFrame();
            }
        });

        v.setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);

        setContentView(v);
    }
}
