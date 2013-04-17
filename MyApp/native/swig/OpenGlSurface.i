%module __OpenGlSurface__

%inline %{
	extern void onSurfaceCreated();
	extern void onSurfaceChanged(int width, int height);
	extern void onDrawFrame();
%}
