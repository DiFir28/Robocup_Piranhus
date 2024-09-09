
// #include"structs.h"



// lisens line_angle;

// byte control_line_Pin[] = { 9, 8, 7 };
// byte slave_line_pins[] = { 24, 25, 26, 27 };

// // struct lisens {
// // bool bool_value = 0;
// // bool broken = 0;
// // short angle = 0;
// // byte distance = 0;
// // short analog_value =0;
// // short value = 1;
// // short max_value = 0;
// // short min_value = 0;
// // short threshold_value= 0;
// // };

// byte delta_index = 0;
// byte min_delta = 0;

// struct lisens line_sensors[32];
// std::vector<lisens> need_angles;

// void setConfigurate(int conf) {
//   for (int conf_i = 2; conf_i > -1; conf_i--) {
//     digitalWrite(control_line_Pin[conf_i], (conf >= pow(2, conf_i)));
//     conf = conf - pow(2, conf_i) * (conf >= pow(2, conf_i));
//   }
// }

// void line_coll() {
//   for (int c = 0; c < 8; c++) {
//     setConfigurate(c);
//     delay(3);
//     for (int step = 0; step < 4; step++) {
//       line_sensors[step * 8 + c].min_value = min(analogRead(slave_line_pins[step]), line_sensors[step * 8 + c].min_value);
//       line_sensors[step * 8 + c].max_value = max(analogRead(slave_line_pins[step]), line_sensors[step * 8 + c].max_value);
//       line_sensors[step * 8 + c].threshold_value = int((line_sensors[step * 8 + c].min_value + line_sensors[step * 8 + c].max_value ) / 2.2);
//       line_sensors[step * 8 + c].broken = ((line_sensors[step * 8 + c].min_value + line_sensors[step * 8 + c].max_value ) < 100);
//       if((line_sensors[step * 8 + c].max_value - line_sensors[step * 8 + c].min_value ) < 200){
//         Serial.println("ERR_LINE");
//       }

//       // Serial.println(line_detect[1][step * 8 + c] > line_detect[0][step * 8 + c]);
//     }
//   }
//   Serial.print("{ ");
//   for (int i = 0; i < 32; i++) {
//     Serial.print(line_sensors[i].threshold_value);
//     Serial.print(" ");
//   }
//   Serial.println("}");
// }


// void line_read(){
//   for (int c = 0; c < 8; c++) {
//     setConfigurate(c);
//     delay(3);
//     for (int step = 0; step < 4; step++) {
//       line_sensors[step * 8 + c].value += int(0.95 * (analogRead(slave_line_pins[step]) - line_sensors[step * 8 + c].value));
//       line_sensors[step * 8 + c].bool_value = (line_sensors[step * 8 + c].value > line_sensors[step * 8 + c].threshold_value);
//       if (line_sensors[step * 8 + c].bool_value && line_sensors[step * 8 + c].broken) {
//         need_angles.push_back(line_sensors[step * 8 + c]);
//         //  Serial.print(need_angles[ret_i]);
//         // Serial.print("/");
//         // Serial.print(abs(math.processing_angle(need_angles[ret_i], need_angles[ret_i-1])) );
//         // Serial.print(" ");
//       }
//     }
//   }
// }

// void line_management() {

//   if (need_angles.size() == 0) {
//     Serial.print("None line");
//     line_angle = 0;
//   } else {
//     int a_del = need_angles.size();
//     while (a_del > 1) {
//       // Serial.print(a_del);
//       // Serial.print(" -> ");
//       for (int id = 0; id < a_del; id++) {
//         // Serial.print(need_angles[id]);
//         //  Serial.print("/");
//         //  Serial.print(abs(math.processing_angle(need_angles[id], need_angles[(id+a_del-1)%a_del])) );
//         // Serial.print("  ");
//         if (abs(math.processing_angle(need_angles[id], need_angles[(id + a_del - 1) % a_del])) < min_delta) {
//           delta_index = id;
//           min_delta = abs(math.processing_angle(need_angles[id], need_angles[(id + a_del - 1) % a_del]));
//         }
//       }
//       if (a_del == 2) {
//         delta_index = 1;
//       }
//       int bis = math.bisector(need_angles[(delta_index + a_del - 1) % a_del], need_angles[delta_index]);
//       //  Serial.println("");
//       need_angles.push_back(bis);

//       std::swap(need_angles[(delta_index + a_del - 1) % a_del], need_angles[a_del]);
//       // need_angles.pop_back();

//       // a_del = need_angles.size();
//       need_angles[(delta_index + a_del - 1) % a_del] = bis;
//       if (a_del != 2) {
//         for (int i = delta_index; i < a_del; i++) {

//           need_angles[i] = need_angles[i + 1];
//         }
//       } else {
//         //Serial.print("?");Serial.print((delta_index + a_del- 1)%a_del);
//       }
//       need_angles.pop_back();
//       need_angles.pop_back();
//       a_del = need_angles.size();
//       // Serial.print(a_del);
//       min_delta = 180;
//       delta_index = 0;
//       delay(3);
//       //Serial.print(" ");

//       // for (int i = 0; i < a_del; i++) {
//       //   Serial.print(need_angles[i]);
//       //   Serial.print("  ");
//       // }
//     }
//     // Serial.print("  ");
//     // Serial.print(need_angles[0]);
//     // Serial.println("");
//     line_angle = need_angles[0];

    
//     min_delta = 180;
//   }

//   while (need_angles.size() != 0) { need_angles.pop_back(); }
// }

// void line_detect(){
// line_read();
// line_management();

// }