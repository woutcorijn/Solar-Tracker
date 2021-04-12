setInterval(reload, 1000);

function reload() {
$("#Update").load(location.href + " #Update")
}
