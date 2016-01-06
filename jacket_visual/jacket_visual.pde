import processing.opengl.*;

void setup()
{
    size(800, 720, OPENGL);
}

void draw()
{   
    background(0, 128, 255);
    lights();
    fill(255, 128, 0);
    pushMatrix();
    translate( 120, 120, 0 );
    righthand();  
    popMatrix();
}
        
void leftforearm()
{
  pushMatrix();
  translate(120,120,0);
  rotateY(-PI/2);
  drawCone(40, 35, 50,200);
  popMatrix();
}

void lefthindarm()
{
  pushMatrix();
  translate(120,120,0);
  rotateY(-PI/2);
  drawCone(40, 35, 55,220);
  popMatrix();
}


void lefthand()
{
     
    //wrist
    
    pushMatrix();
    translate( 120, 120, 0 );
    rotateX( PI/6 );
    box(120,140,20);  
    popMatrix();
   
   //little
    
    pushMatrix();
    translate( 205, 165, 0 );
    rotateZ(PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 40 );
    popMatrix();
    
    pushMatrix();
    translate( 260, 165, 0 );
    rotateZ(-PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 35 );
    popMatrix();    
    
   //ring
    
    pushMatrix();
    translate( 210, 135, 0 );
    rotateZ(PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 50 );
    popMatrix();
   
    pushMatrix();
    translate( 265, 135, 0 );
    rotateZ(-PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 50 );
    popMatrix();
    
   //middle
    
    pushMatrix();
    translate( 215, 105, 0 );
    rotateZ(PI/6);    
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 55 );
    popMatrix();

    pushMatrix();
    translate( 270, 105, 0 );
    rotateZ(-PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 55 );
    popMatrix();
    
   //index
    
    pushMatrix();
    translate( 220, 75, 0 );
    rotateZ(PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 50 );
    popMatrix();

    pushMatrix();
    translate( 275, 75, 0 );
    rotateZ(-PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 50 );
    popMatrix();
    
   //thumb
 
    pushMatrix();
    translate( 70, 30, 5 );
    rotateZ(PI/2);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 50 );
    popMatrix();    
    
}  
 void rightforearm()
{
  pushMatrix();
  translate(120,120,0);
  rotateY(-PI/2);
  drawCone(40, 35, 50,200);
  popMatrix();
}

void righthindarm()
{
  pushMatrix();
  translate(120,120,0);
  rotateY(-PI/2);
  drawCone(40, 35, 55,220);
  popMatrix();
}
 void righthand()
{
     
    //wrist
    
    pushMatrix();
    translate( 120, 120, 0 );
    rotateX( PI/6 );
    box(120,140,20);  
    popMatrix();
   
   //little
    
    pushMatrix();
    translate( 205, 165, 0 );
    rotateZ(PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 40 );
    popMatrix();
    
    pushMatrix();
    translate( 260, 165, 0 );
    rotateZ(-PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 35 );
    popMatrix();    
    
   //ring
    
    pushMatrix();
    translate( 210, 135, 0 );
    rotateZ(PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 50 );
    popMatrix();
   
    pushMatrix();
    translate( 265, 135, 0 );
    rotateZ(-PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 50 );
    popMatrix();
    
   //middle
    
    pushMatrix();
    translate( 215, 105, 0 );
    rotateZ(PI/6);    
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 55 );
    popMatrix();

    pushMatrix();
    translate( 270, 105, 0 );
    rotateZ(-PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 55 );
    popMatrix();
    
   //index
    
    pushMatrix();
    translate( 220, 75, 0 );
    rotateZ(PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 50 );
    popMatrix();

    pushMatrix();
    translate( 275, 75, 0 );
    rotateZ(-PI/6);
    rotateY( -PI/2 );
    drawCylinder( 20,  11, 50 );
    popMatrix();
    
   //thumb
 
    pushMatrix();
    translate( 50, 200, 5 );
    rotateZ(PI/2);
    drawCylinder( 20,  11, 50 );
    popMatrix();    
    
}

void drawCylinder( int sides, float r, float h)
{
    float angle = 360 / sides;
    float halfHeight = h / 2;

    // draw top of the tube
    beginShape();
    for (int i = 0; i < sides; i++) {
        float x = cos( radians( i * angle ) ) * r;
        float y = sin( radians( i * angle ) ) * r;
        vertex( x, y, -halfHeight);
    }
    endShape(CLOSE);

    // draw bottom of the tube
    beginShape();
    for (int i = 0; i < sides; i++) {
        float x = cos( radians( i * angle ) ) * r;
        float y = sin( radians( i * angle ) ) * r;
        vertex( x, y, halfHeight);
    }
    endShape(CLOSE);
    
    // draw sides
    beginShape(TRIANGLE_STRIP);
    for (int i = 0; i < sides + 1; i++) {
        float x = cos( radians( i * angle ) ) * r;
        float y = sin( radians( i * angle ) ) * r;
        vertex( x, y, halfHeight);
        vertex( x, y, -halfHeight);    
    }
    endShape(CLOSE);
}

void drawCone( int sides, float r1, float r2, float h)
{
    float angle = 360 / sides;
    float halfHeight = h / 2;

    // draw top of the tube
    beginShape();
    for (int i = 0; i < sides; i++) {
        float x = cos( radians( i * angle ) ) * r1;
        float y = sin( radians( i * angle ) ) * r1;
        vertex( x, y, -halfHeight);
    }
    endShape(CLOSE);

    // draw bottom of the tube
    beginShape();
    for (int i = 0; i < sides; i++) {
        float x = cos( radians( i * angle ) ) * r2;
        float y = sin( radians( i * angle ) ) * r2;
        vertex( x, y, halfHeight);
    }
    endShape(CLOSE);
    
    // draw sides
    beginShape(TRIANGLE_STRIP);
    for (int i = 0; i < sides + 1; i++) {
        float x1 = cos( radians( i * angle ) ) * r1;
        float y1 = sin( radians( i * angle ) ) * r1;
        float x2 = cos( radians( i * angle ) ) * r2;
        float y2 = sin( radians( i * angle ) ) * r2;
        vertex( x1, y1, -halfHeight);
        vertex( x2, y2, halfHeight);    
    }
    endShape(CLOSE);

}
