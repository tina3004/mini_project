const express = require("express");
const cors = require("cors");
const app = express();
const port = 3000;

let rfidData = null;
app.use(cors());
app.use(express.json());

app.post("/Canteen-Management/rfid", (req, res) => {
  rfidData = req.body;
  res.sendStatus(200);
});

app.get("/Canteen-Management/rfid", (req, res) => {
  res.json(rfidData);
  rfidData = null; // Clear data after sending
});

app.listen(port, () => {
  console.log(`Server listening at http://localhost:${port}`);
});