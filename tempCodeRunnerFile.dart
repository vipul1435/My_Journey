import 'dart:io';
double min_time({required int n, required Set s,required int k}){
  int comp = s.length;
  int rem = n-comp;
  double ans = comp*k+rem*(k/2);
  return ans;
}
void main(){
  String? input= stdin.readLineSync();
  int n = input!.split(" ").map((e) => int.parse(e)).first;
  int k= input.split(" ").map((e) => int.parse(e)).last;
  var val = Set();
  val=stdin.readLineSync()!.split(" ").map((e) => int.parse(e)).toSet();
  var time = min_time(n: n, s: val, k: k);
  print(time);
}