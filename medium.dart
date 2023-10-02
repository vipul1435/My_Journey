import 'dart:io';

int obtained_marks({required int n,required List cordinates}){
  int marks=0;
  for(var it in cordinates){
    var x_cord = Set();
    var y_cord = Set();
    for(int i=0;i<6;i++){
      if(i.isEven){
        x_cord.add(it[i]);
      } else {
        y_cord.add(it[i]);
      }
    }
    if(x_cord.length==2 && y_cord.length==2){
      marks+=4;
    } else {
      marks-=1;
    }
  }
  return marks;
}
void main() {
  int n = int.parse(stdin.readLineSync().toString());
  List cordinates =[];
  for(int i=0;i<n;i++){
    List temp = stdin.readLineSync()!.split(" ").map((e) => int.parse(e)).toList();
    cordinates.add(temp);
  }
  int marks = obtained_marks(n: n, cordinates: cordinates);
  stdout.write(marks);
}