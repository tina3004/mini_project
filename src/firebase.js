import { initializeApp } from "firebase/app";
import { getDatabase } from "firebase/database";
import { getAuth } from "firebase/auth";

const firebaseConfig = {
  apiKey: "AIzaSyCcvObo8ywlXqGbDA8FdCGT6SwFdhlQX6A",
  authDomain: "canteenmanagement-fd2c1.firebaseapp.com",
  databaseURL: "https://canteenmanagement-fd2c1-default-rtdb.asia-southeast1.firebasedatabase.app/",
  projectId: "canteenmanagement-fd2c1",
  storageBucket: "canteenmanagement-fd2c1.firebasestorage.app",
  messagingSenderId: "653207161222",
  appId: "1:653207161222:web:743fb5f96a8d1381a38407",
  measurementId: "G-6SJV8JLQXW"
};



// Initialize Firebase
const app = initializeApp(firebaseConfig);
const database = getDatabase(app);
const auth = getAuth(app);

export { auth, database };
