import { useState, useEffect } from "react";
import axios from "axios";

const useRFID = () => {
  const [userId, setUserId] = useState(null);

  useEffect(() => {
    const fetchRFIDData = async () => {
      try {
        const response = await axios.get("http://192.168.1.6:3000/Canteen-Management/rfid");
        // if (response.data && response.data.userId) {
        //   setUserId(response.data.userId);
        //   console.log("RFID data:", response.data);
        // }

        if (response.data) {
          setUserId(response.data.userId);
          console.log("RFID data:", response.data);
        }
        
      } catch (error) {
        console.error("Error fetching RFID data:", error);
      }
    };

    const intervalId = setInterval(fetchRFIDData, 1000); // Poll every second

    return () => clearInterval(intervalId);
  }, []);

  return userId;
};

export default useRFID;