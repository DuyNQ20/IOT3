const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title></title>
</head>
<style>
  .wrapper {
    width: 50%;
    height: auto;
    background: lightgreen;
    color: white;
    margin: auto;
    text-align: center;
    padding: 20px;
}

input[type="button"] {
    width: 100px;
    padding: 5px;
    background: orange;
    color: wheat;
}

h1 {
    margin-top: 0;
}
</style>
<body>
  <div class="wrapper">
    <h1>Điều khiển đèn</h1>
    <input type="button" onclick="ledControl(1)" value="ON" name="">
    <input type="button" onclick="ledControl(0)" value="OFF" name="">
  </div>
  
  <script type="text/javascript">

    function ledControl(led) {
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET", "led?status_led="+led, true);
      xhttp.send();
    }
    
  </script>
</body>
</html>
)=====";
