setInterval(reload, 1000);
document.getElementById("data").style.visibility = "hidden";

function reload() {
$("#data").load(location.href + " #data")
document.getElementById("data").style.visibility = "visible";
}