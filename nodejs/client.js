var WebSocket = require('ws'),
    ws = new WebSocket('ws://localhost:8080');

ws.on('open', function(){
  ws.send('something');
});

ws.on('message', function(message){
  console.log('recieved %s\n' , message);
});
